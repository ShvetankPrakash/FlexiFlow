import matplotlib.pyplot as plt
from lifetime_modeling import *

def plot_all_workloads_lifetime(lifetime_yrs, inf_freq, carbon_intensity, core_freq, output_pdf="all_workloads_lifetime.pdf"):
    workloads = list(execution_time.keys())
    n = len(workloads)
    ncols = 5
    nrows = 2  # 10/5 = 2 rows for 10 workloads

    fig, axes = plt.subplots(nrows, ncols, figsize=(8 * ncols, 6 * nrows))
    axes = axes.flatten()

    for i, workload in enumerate(workloads):
        ax = axes[i]
        plt.sca(ax)
        plot_total_carbon_vs_lifetime_ax(
            ax=ax,
            workload_choice=workload,
            lifetime_yrs=lifetime_yrs,
            inf_freq=inf_freq,
            carbon_intensity=carbon_intensity,
            core_freq=core_freq
        )
        ax.set_title(str(workload))
    # Hide any unused subplots
    for j in range(i+1, len(axes)):
        fig.delaxes(axes[j])
    plt.tight_layout()
    plt.savefig(output_pdf, format="pdf")
    plt.close(fig)

def plot_all_workloads_frequency(lifetime_yrs, inf_freq, carbon_intensity, core_freq, output_pdf="all_workloads_frequency.pdf"):
    workloads = list(execution_time.keys())
    n = len(workloads)
    ncols = 5
    nrows = 2  # 10/5 = 2 rows for 10 workloads

    fig, axes = plt.subplots(nrows, ncols, figsize=(8 * ncols, 6 * nrows))
    axes = axes.flatten()

    for i, workload in enumerate(workloads):
        ax = axes[i]
        plt.sca(ax)
        plot_total_carbon_vs_frequency_ax(
            ax=ax,
            workload_choice=workload,
            lifetime_yrs=lifetime_yrs,
            inf_freq=inf_freq,
            carbon_intensity=carbon_intensity,
            core_freq=core_freq
        )
        ax.set_title(str(workload))
    # Hide any unused subplots
    for j in range(i+1, len(axes)):
        fig.delaxes(axes[j])
    plt.tight_layout()
    plt.savefig(output_pdf, format="pdf")
    plt.close(fig)

def plot_all_workloads_inferences(lifetime_yrs, inf_freq, carbon_intensity, core_freq, output_pdf="all_workloads_inferences.pdf"):
    workloads = list(execution_time.keys())
    n = len(workloads)
    ncols = 5
    nrows = 2  # 10/5 = 2 rows for 10 workloads

    fig, axes = plt.subplots(nrows, ncols, figsize=(8 * ncols, 6 * nrows))
    axes = axes.flatten()

    for i, workload in enumerate(workloads):
        ax = axes[i]
        plt.sca(ax)
        plot_total_carbon_vs_num_inferences_ax(
            ax=ax,
            workload_choice=workload,
            lifetime_yrs=lifetime_yrs,
            inf_freq=inf_freq,
            carbon_intensity=carbon_intensity,
            core_freq=core_freq
        )
        ax.set_title(str(workload))
    # Hide any unused subplots
    for j in range(i+1, len(axes)):
        fig.delaxes(axes[j])
    plt.tight_layout()
    plt.savefig(output_pdf, format="pdf")
    plt.close(fig)

def plot_all_workloads_best_system_region(lifetime_yrs, inf_freq, carbon_intensity, core_freq, output_pdf="all_workloads_best_system_region.pdf"):
    workloads = list(execution_time.keys())
    n = len(workloads)
    ncols = 5
    nrows = 2  # 10/5 = 2 rows for 10 workloads

    fig, axes = plt.subplots(nrows, ncols, figsize=(8 * ncols, 6 * nrows))
    axes = axes.flatten()

    for i, workload in enumerate(workloads):
        ax = axes[i]
        plt.sca(ax)
        plot_best_system_region_map_ax(
            ax=ax,
            workload_choice=workload,
            lifetime_yrs=lifetime_yrs,
            inf_freq=inf_freq,
            carbon_intensity=carbon_intensity,
            core_freq=core_freq
        )
        ax.set_title(str(workload))
    # Hide any unused subplots
    for j in range(i+1, len(axes)):
        fig.delaxes(axes[j])
    plt.tight_layout()
    plt.savefig(output_pdf, format="pdf")
    plt.close(fig)

if __name__ == '__main__':
    plot_all_workloads_lifetime(
        lifetime_yrs=1,
        inf_freq=1,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf="all_workloads_lifetime.pdf"
    )
    plot_all_workloads_frequency(
        lifetime_yrs=1,
        inf_freq=1,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf="all_workloads_frequency.pdf"
    )
    plot_all_workloads_inferences(
        lifetime_yrs=1,
        inf_freq=1,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf="all_workloads_inferences.pdf"
    )
    plot_all_workloads_best_system_region(
        lifetime_yrs=1,
        inf_freq=1,
        carbon_intensity=367,
        core_freq=10000,
        output_pdf="all_workloads_best_system_region.pdf"
    )
