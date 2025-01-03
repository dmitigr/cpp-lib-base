# -*- cmake -*-
#
# Copyright 2024 Dmitry Igrishin
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# ------------------------------------------------------------------------------
# Info
# ------------------------------------------------------------------------------

dmitigr_libs_set_library_info(base 0 0 0 "Base utilities")

# ------------------------------------------------------------------------------
# Sources
# ------------------------------------------------------------------------------

set(dmitigr_base_headers
  algorithm.hpp
  assert.hpp
  autostack.hpp
  chrox.hpp
  contract.hpp
  diagnostic.hpp
  endianness.hpp
  enum_bitmask.hpp
  err.hpp
  errc.hpp
  errctg.hpp
  exceptions.hpp
  fifo_array.hpp
  fifo_string.hpp
  memory.hpp
  noncopymove.hpp
  ret.hpp
  traits.hpp
  tuple.hpp
  )

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------

if(DMITIGR_LIBS_TESTS)
  set(dmitigr_base_tests chrox diag fifo_array fifo_string)
endif()
