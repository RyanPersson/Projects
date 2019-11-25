import numpy as np
import matplotlib.pyplot as plt


def generate_poly(power) :
    def poly(base) :
        return base**power
    return poly

f = generate_poly(2)
print(f(3))
