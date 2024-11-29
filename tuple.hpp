// -*- C++ -*-
//
// Copyright 2024 Dmitry Igrishin
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DMITIGR_BASE_TUPLE_HPP
#define DMITIGR_BASE_TUPLE_HPP

#include <cstddef>
#include <tuple>
#include <utility>

namespace dmitigr {
namespace detail {

template<std::size_t ... I, typename Tuple, typename Predicate>
static bool is_all_of(std::index_sequence<I...>,
  const Tuple& tuple, const Predicate& predicate) noexcept
{
  constexpr auto tsz = std::tuple_size<std::decay_t<decltype(tuple)>>();
  static_assert(sizeof...(I) == tsz);
  return (predicate(std::get<I>(tuple)) && ...);
}

} // namespace detail

template<typename Tuple, typename Predicate>
static bool is_all_of(const Tuple& tuple, const Predicate& predicate) noexcept
{
  constexpr auto tsz = std::tuple_size<std::decay_t<decltype(tuple)>>();
  return detail::is_all_of(std::make_index_sequence<tsz>{}, tuple, predicate);
}

} // namespace dmitigr

#endif  // DMITIGR_BASE_TUPLE_HPP
