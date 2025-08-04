import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import matplotlib.patches as mpatches

# Define global variables for max and min values
MIN_LIFETIME = 0.01
MAX_LIFETIME = 20
MIN_INF_FREQ = 1
MAX_INF_FREQ = 365*100000
MIN_CORE_FREQ = 1000
MAX_CORE_FREQ = 100000

system_colors = {'Serv': 'blue', 'Qerv': 'orange', 'Herv': 'green'}

# -------------------------
# 1) Define Internal Data
# -------------------------
system_specs = {
    "Serv": {"area": 2.93, "power": 17.7451},
    "Qerv": {"area": 3.68, "power": 21.0650},
    "Herv": {"area": 4.50, "power": 24.9934},
}

rf_sram = 128 # Implementing register file in SRAM for space-saving

# Define SRAM and LPROM constants (in bits)
sram_power = 0.0018
sram_area = 0.00176
lprom_power = 0 # negligible
lprom_area = 0.000359
sram_overhead_power = 0.0002 # per bit
sram_overhead_area = 0.0003 # per bit

# Global dictionaries for memory values
sram = {}
lprom = {}

def load_memory_from_csv(csv_path="memory.csv"):
    global sram, lprom
    df = pd.read_csv(csv_path)
    temp_sram = {}
    temp_lprom = {}
    for _, row in df.iterrows():
        workload = row["Workload"]
        temp_sram[workload] = int(row["sram"])
        temp_lprom[workload] = int(row["lprom"])
    sram.clear()
    sram.update(temp_sram)
    lprom.clear()
    lprom.update(temp_lprom)

# Define carbon intensity values for each power source
# gCO2 eq / kWhr
# Source: https://www.eia.gov/tools/faqs/faq.php?id=74&t=11
# And: https://www.energy.gov/eere/wind/articles/how-wind-can-help-us-breathe-easier
carbon_intensity_values = {
    "US Avg (2023)": "367",
    "Petroleum": "1116",
    "Coal": "1048",
    "Solar": "28",
    "Nuclear": "13",
    "Wind": "12",
    "Custom": ""
}

# These need to be loaded in
execution_time = {}
embodied_values = {}

def load_embodied_values_from_csv(csv_path="embodied-carbon.csv"):
    global embodied_values
    df = pd.read_csv(csv_path)
    temp_embodied_values = {}
    # Build the embodied_values dictionary from the DataFrame
    for _, row in df.iterrows():
        workload = row["Workload"]
        cpu = row["CPU Design"]
        min_val = row["Carbon Footprint Min (gCO2e)"]
        max_val = row["Carbon Footprint Max (gCO2e)"]
        if workload not in temp_embodied_values:
            temp_embodied_values[workload] = {}
        temp_embodied_values[workload][cpu] = {
            "Carbon Footprint Min (gCO2e)": min_val,
            "Carbon Footprint Max (gCO2e)": max_val
        }
    embodied_values.clear()
    embodied_values.update(temp_embodied_values)
    

def load_execution_time_from_csv(csv_path="timing.csv"):
    global execution_time
    df = pd.read_csv(csv_path)
    temp_execution_time = {}
    for _, row in df.iterrows():
        workload = row["Workload"]
        temp_execution_time[workload] = {
            "Serv": float(row["Serv"]),
            "Qerv": float(row["Qerv"]),
            "Herv": float(row["Herv"]),
        }
    execution_time.clear()
    execution_time.update(temp_execution_time)
    return execution_time

def compute_total_carbon(
    system: str,
    workload: str,
    lifetime_yrs: float,
    inf_freq: float, # per year
    carbon_intensity: float,
    core_freq: float
):
    """
    Compute the total carbon footprint of a given system with the user-specified parameters.
    Returns (embodied_carbon, operational_carbon, total_carbon).
    """
    sram_bytes = sram[workload] + rf_sram
    lprom_bytes = lprom[workload]

    # 1) Calculate total area (Precomputed in CSV)
    # core_area = system_specs[system]["area"]
    # device_area = core_area + (sram_area + sram_overhead_area) * sram_bytes * 8 + lprom_area * lprom_bytes * 8
    # 2) Embodied carbon (Precomputed in CSV)
    embodied_carbon = embodied_values[workload][system]["Carbon Footprint Max (gCO2e)"]
    # 3) Operational carbon
    system_power = system_specs[system]["power"]
    total_power = system_power + (sram_power + sram_overhead_power) * sram_bytes * 8 + lprom_power * lprom_bytes * 8

    # Convert lifetime in years to total inferences:
    total_inferences = inf_freq * lifetime_yrs
    time_per_inference = execution_time[workload][system] / core_freq  # Adjusted with core frequency
    total_energy = total_power * time_per_inference * total_inferences
    operational_carbon = total_energy * carbon_intensity

    total_carbon = embodied_carbon + operational_carbon

    return embodied_carbon, operational_carbon, total_carbon

def plot_total_carbon_vs_lifetime_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot total carbon vs. device lifetime for each system on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    lifetimes = np.linspace(MIN_LIFETIME, MAX_LIFETIME, 50)
    plot_data = []
    for system in system_specs:
        total_carbons = []
        for lifetime in lifetimes:
            _, _, total = compute_total_carbon(system, workload_choice, lifetime, inf_freq, carbon_intensity, core_freq)
            total_carbons.append(total)
        plot_data.append(pd.DataFrame({
            "Lifetime": lifetimes,
            "Total Carbon": total_carbons,
            "System": system
        }))
    df_plot = pd.concat(plot_data, ignore_index=True)
    sns.lineplot(data=df_plot, x="Lifetime", y="Total Carbon", hue="System", palette=system_colors, ax=ax)
    ax.axvline(x=lifetime_yrs, color='gray', linestyle ='--', linewidth=1)
    ax.set_title(f"Total Carbon vs. Lifetime\nWorkload: {workload_choice}")
    ax.set_xlabel("Lifetime (years)")
    ax.set_ylabel("Total Carbon Footprint (gCO₂-eq)")
    ax.legend()

def plot_total_carbon_vs_frequency_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot total carbon vs. inference frequency for each system on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    inf_frequencies = np.logspace(np.log10(MIN_INF_FREQ), np.log10(MAX_INF_FREQ), 50)
    max_found_valid_freq = MIN_INF_FREQ
    valid_frequencies_any = []
    plot_data = []

    for system in system_specs:
        total_carbons = []
        valid_frequencies = []
        for freq in inf_frequencies:
            if execution_time[workload_choice][system] / core_freq <= 365 * 3600 / freq:
                _, _, total = compute_total_carbon(system, workload_choice, lifetime_yrs, freq, carbon_intensity, core_freq)
                total_carbons.append(total)
                valid_frequencies.append(freq)
                max_found_valid_freq = max(max_found_valid_freq, freq)
            else:
                break
        valid_frequencies_any.extend(valid_frequencies)
        plot_data.append(pd.DataFrame({
            "Frequency": valid_frequencies,
            "Total Carbon": total_carbons,
            "System": system
        }))

    if len(valid_frequencies_any) > 0:
        df_plot = pd.concat(plot_data, ignore_index=True)
        sns.lineplot(data=df_plot, x="Frequency", y="Total Carbon", hue="System", palette=system_colors, ax=ax, legend=True)
        ax.axvline(x=inf_freq, color='gray', linestyle ='--', linewidth=1)
        ax.set_xscale('log')
        ax.set_yscale('log')
        ax.set_title(f"Total Carbon vs. Task Frequency\nWorkload: {workload_choice}")
        ax.set_xlabel("Task Frequency (tasks/year)")
        ax.set_ylabel("Total Carbon Footprint (gCO₂-eq)")
        ax.legend()
    else:
        ax.set_title(f"No valid frequencies for {workload_choice} between {MIN_INF_FREQ} and {MAX_INF_FREQ} tasks/year")

def plot_total_carbon_vs_num_inferences_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot total carbon vs. number of inferences for each system on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    inferences = np.logspace(np.log10(MIN_INF_FREQ * MIN_LIFETIME), np.log10(MAX_INF_FREQ * MAX_LIFETIME), 50)
    plot_data = []
    for system in system_specs:
        total_carbons = []
        for inf in inferences:
            lt = inf / inf_freq
            _, _, total = compute_total_carbon(system, workload_choice, lt, inf_freq, carbon_intensity, core_freq)
            total_carbons.append(total)
        plot_data.append(pd.DataFrame({
            "Inferences": inferences,
            "Total Carbon": total_carbons,
            "System": system
        }))
    df_plot = pd.concat(plot_data, ignore_index=True)
    sns.lineplot(data=df_plot, x="Inferences", y="Total Carbon", hue="System", palette=system_colors, ax=ax)
    ax.axvline(x=inf_freq * lifetime_yrs, color='gray', linestyle='--', linewidth=1)
    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.set_title(f"Total Carbon vs. Number of Executed Tasks\nWorkload: {workload_choice}")
    ax.set_xlabel("Number of Tasks")
    ax.set_ylabel("Total Carbon Footprint (gCO₂-eq)")
    ax.legend()

def plot_best_system_region_map_ax(ax, workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq, hashes_grey = False):
    """
    Plot a 2D region map of best system choice for a grid of (lifetime, inference frequency) on the given axis.
    """
    carbon_intensity = float(carbon_intensity) / 3600 / 1000000
    core_freq = float(core_freq)

    # Create a fine grid for smooth contours
    lifetime_grid = np.logspace(np.log10(MIN_LIFETIME), np.log10(MAX_LIFETIME), 200)
    inf_freq_grid = np.logspace(np.log10(MIN_INF_FREQ), np.log10(MAX_INF_FREQ), 200)
    X, Y = np.meshgrid(lifetime_grid, inf_freq_grid)
    systems = list(system_specs.keys())

    carbon_values = np.ones((len(systems), len(inf_freq_grid), len(lifetime_grid))) * np.inf
    max_found_valid_freq = MIN_INF_FREQ
    for sys_idx, sys_name in enumerate(systems):
        for i, freq in enumerate(inf_freq_grid):
            for j, lt in enumerate(lifetime_grid):
                _, _, total = compute_total_carbon(sys_name, workload_choice, lt, freq, carbon_intensity, core_freq)
                carbon_values[sys_idx, i, j] = total
                if execution_time[workload_choice][sys_name] / core_freq <= 365 * 3600 / freq:
                    max_found_valid_freq = max(max_found_valid_freq, freq)

    best_indices = np.argmin(carbon_values, axis=0)

    # Create contours where systems intersect
    for i in range(len(systems)):
        for j in range(i+1, len(systems)):
            diff = carbon_values[i] - carbon_values[j]
            mask = (best_indices == i) | (best_indices == j)
            masked_diff = np.ma.masked_where(~mask, diff)
            ax.contour(X, Y, masked_diff, levels=[0], colors='black', linestyles='-', linewidths=1)

    # Color the regions and add legend
    cmap = ListedColormap([system_colors[sys] for sys in systems][np.min(best_indices):np.max(best_indices)+1])
    ax.pcolormesh(X, Y, best_indices, shading='auto', alpha=0.3, cmap=cmap)
    handles = [plt.Line2D([0], [0], marker='o', color='w', label=sys, markersize=10, markerfacecolor=system_colors[sys]) for sys in systems]
    freq_mask = Y > max_found_valid_freq
    hatch_mask = np.where(freq_mask, 1, np.nan)
    # Use contour instead of contourf to ensure hatches (crosshatching) are visible
    if hashes_grey:
        ax.contourf(X, Y, hatch_mask, levels=[0.5, 1.5], colors='grey', hatches=['xx'])._hatch_color=(0,0,0,1)
        crosshatch_patch = mpatches.Patch(facecolor='grey', hatch='xx', label='Task Freq. Not Possible', edgecolor='black')
    else:
        ax.contourf(X, Y, hatch_mask, levels=[0.5, 1.5], colors='none', hatches=['xx'])._hatch_color=(0,0,0,1)
        crosshatch_patch = mpatches.Patch(facecolor='none', hatch='xx', label='Task Freq. Not Possible', edgecolor='black')
    handles.append(crosshatch_patch)
    ax.legend(handles=handles, title="Systems", loc='lower left')

    # Plot a star marker at the currently selected lifetime & inference frequency
    ax.plot([lifetime_yrs], [inf_freq], marker='*', color='red', markersize=10)

    ax.set_xscale('log')
    ax.set_yscale('log')
    ax.set_title("Best System Choice by (Lifetime, Task Freq)")
    ax.set_xlabel("Lifetime (years)")
    ax.set_ylabel("Task Frequency (tasks/year)")

    return X, Y, hatch_mask

def plot_carbon_vs_lifetime(workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq):
    """
    Plot all carbon plots for the given parameters in a 2x2 grid of subplots.
    Returns the matplotlib Figure object.
    """
    fig, axs = plt.subplots(2, 2, figsize=(16, 12))
    plt.subplots_adjust(hspace=0.3, wspace=0.25)

    plot_total_carbon_vs_lifetime_ax(axs[0, 0], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)
    plot_total_carbon_vs_frequency_ax(axs[0, 1], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)
    plot_total_carbon_vs_num_inferences_ax(axs[1, 0], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)
    plot_best_system_region_map_ax(axs[1, 1], workload_choice, lifetime_yrs, inf_freq, carbon_intensity, core_freq)

    # Optionally, set a main title
    fig.suptitle(f"Carbon Footprint Analysis for {workload_choice}", fontsize=18)
    return fig