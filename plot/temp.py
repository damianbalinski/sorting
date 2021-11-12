y0 = np.zeros(300)
left = np.quantile(data, 0.45)
right = np.quantile(data, 0.55)
mask = np.logical_and(left < x, x < right)
ax.fill_between(x, y, y0, where=mask, facecolor='green', interpolate=True)