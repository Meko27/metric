import numpy
from metric.distance import VOI_normalized

v1 = numpy.float_([
    [5.0, 5.0],
    [2.0, 2.0],
    [3.0, 3.0],
    [5.0, 5.0],
])

v2 = numpy.float_([
    [5.0, 5.0],
    [2.0, 2.0],
    [3.0, 3.0],
    [1.0, 1.0],
])

result = VOI_normalized(3, 2)(v1, v2)
print(f'VOI normalized: {result:.5f}')
