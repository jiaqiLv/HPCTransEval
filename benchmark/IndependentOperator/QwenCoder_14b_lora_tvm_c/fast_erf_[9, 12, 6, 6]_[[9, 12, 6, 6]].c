void default_function_kernel(float* T_fast_erf, float* data, int size) {
#pragma omp parallel for
  for (int i = 0; i < size; ++i) {
    float x = data[i];
    x = fminf(fmaxf(x, -4.0f), 4.0f);
    float p = x * x;
    float q = p * p;
    float r = q * p;
    float s = r * q;
    float t = s * r;
    float u = t * s;
    float v = u * t;
    float w = v * u;
    float erf_value = (x * ((((((((1.283791826086136e-10f * w) - 1.153981709599617e-08f) * v) + 1.708061256972455e-06f) * u) - 1.637991729997070e-04f) * t) + 2.057831578703050e-02f) * s) - 3.259033660616745e-01f) * q) + 1.0f;
    T_fast_erf[i] = erf_value;
  }
}