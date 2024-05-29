# Fibonacci Sphere

Spawn N evenly spread out points on a sphere

```c#
float goldenRatio = (1+ Sqrt(5)) / 2;
float angleIncrement = TAU * goldenRatio;

for(int i = 0; i < numPoints; i++) {
	float t = (float) i / numPoints;
	float angle1 = Acos(1 - 2 * t);
	float angle2 = angleIncrement * i;
	float x = Sin(angle1) * Cos(angle2);
	float y = Sin(angle1) * Sin(angle2);
	float z = Cos(angle1);
	Vector3 poinOnSphere = new Vector3(x, y, z);
}
```

# Tanh Approximate

```cpp
return x * (27.0 + x * x) / (27.0 + 9.0 * x * x);
```
