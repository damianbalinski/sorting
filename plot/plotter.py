class Plotter:

    def limits(self, ax, metadata):
        ax.set_ylim(ymin=0, ymax=metadata.ymax)
        ax.set_xlim(xmin=metadata.xmin, xmax=metadata.xmax)

    def labels(self, ax, metadata):
        ax.set(
            title=metadata.title,
            xlabel=metadata.xlabel,
            ylabel=metadata.ylabel
        )

    def legend(self, ax, metadata):
        handles = self.legend_handles(ax, metadata)
        if metadata.legend == 'inside':
            ax.legend(handles=handles)
        elif metadata.legend == 'outside':
            ax.legend(handles=handles, loc='center left', bbox_to_anchor=(1, 0.5))
        else:
            pass

    def grid(self, ax, metadata):
        ax.grid()

    def legend_handles(self, ax, metadata):
        if metadata.lines:
            for line in ax.lines: line.set_label(s='')
        handles, labels = ax.get_legend_handles_labels()
        if metadata.lines:
            handles.extend(metadata.lines)
        return handles
