
import cpp_lib

import numpy as np
import time
from functools import wraps


def time_func(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        out = func(*args, **kwargs)
        print(f"{func.__name__} - {time.time() - start} s")
        return out
    return wrapper


@time_func
def scale_list_by_two_cpp(x):
    return cpp_lib.scale_by_two(x)

@time_func
def scale_list_by_two_python(x):
    return [e * 2 for e in x]

x_a = np.arange(1e8)
x_l = x_a.tolist() 
print(f"Array size: {x_a.shape}")
print(scale_list_by_two_python(x_l)[:10])
print(scale_list_by_two_cpp(x_a)[:10])