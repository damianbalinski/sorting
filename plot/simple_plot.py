import matplotlib.pyplot as plt


def simple_plot(config):
    plt.style.use('science')

    fig, ax = plt.subplots()
    for p in config.plots:
        ax.plot(p.x, p.y)

    ax.set(
        title=config.title,
        xlabel=config.x_label,
        ylabel=config.y_label
    )
    ax.legend([p.label for p in config.plots])
    ax.grid()

    fig.savefig(config.output, dpi=300)
    plt.show()
