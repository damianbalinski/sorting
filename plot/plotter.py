class Plotter:

    def limits(self, ax, metadata):
        ax.set_ylim(ymin=0, ymax=metadata.ymax)
        ax.set_xlim(xmin=0, xmax=metadata.xmax)

    def labels(self, ax, metadata):
        ax.set(
            title=metadata.title,
            xlabel=metadata.xlabel,
            ylabel=metadata.ylabel
        )

    def legend(self, ax, metadata):
        if metadata.legend == 'inside':
            ax.legend()
        elif metadata.legend == 'outside':
            ax.legend(loc='center left', bbox_to_anchor=(1, 0.5))
        else:
            pass

    def grid(self, ax, metadata):
        ax.grid()
