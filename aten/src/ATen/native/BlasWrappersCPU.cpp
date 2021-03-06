#include <ATen/ATen.h>
#include <ATen/NativeFunctions.h>
#include <ATen/LegacyTHFunctionsCPU.h>

// These are wrappers around the TH Linear Algebra / BLAS wrappers (mv, mm, bmm).

namespace at {
namespace native {

Tensor & mm_cpu_out(Tensor & result, const Tensor & self, const Tensor & mat2) {
  result.resize_({ self.size(0), mat2.size(1) });
  return legacy::cpu::_th_addmm_out(result, result, self, mat2, 0, 1);
}

Tensor mm_cpu(const Tensor & self, const Tensor & mat2) {
  Tensor result = at::empty({0}, self.options());
  return mm_cpu_out(result, self, mat2);
}

} // namespace native
} // namespace at
