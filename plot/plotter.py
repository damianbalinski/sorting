class Plotter:

    def limits(self, ax, invariants):
        ax.set_ylim(ymin=0)
        ax.set_xlim(xmin=0, xmax=invariants.n)

    def labels(self, ax, invariants):
        ax.set(
            title=invariants.title,
            xlabel=invariants.xlabel,
            ylabel=invariants.ylabel
        )

    def legend(self, ax, invariants):
        if invariants.legend == 'inside':
            ax.legend()
        elif invariants.legend == 'outside':
            ax.legend(loc='center left', bbox_to_anchor=(1, 0.5))
        else:
            pass

    def grid(self, ax, invariants):
        ax.grid()
