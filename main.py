# A simple python code use demonstrate use of shapefile reading

import matplotlib.pyplot as plt
import shapefile as shp

with shp.Reader("test.shp", "test.dbf") as sf:
 for shape in sf.shapeRecords():
  x = [i[0] for i in shape.shape.points[:]]
  y = [i[1] for i in shape.shape.points[:]]
  plt.plot(x, y)
  plt.show()
