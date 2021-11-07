class Plotter:

    def limits(self, ax, metadata):
        ax.set_ylim(ymin=0)
        ax.set_xlim(xmin=0, xmax=metadata.n)

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
