// Copyright 2020 the deepx authors.
// Author: Yafei Zhang (kimmyzhang@tencent.com)
// Author: Shuting Guo (tinkleguo@tencent.com)
//

#pragma once
#include <deepx_core/common/stream.h>
#include <deepx_core/tensor/data_type.h>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace deepx_core {

/************************************************************************/
/* PullRequest */
/************************************************************************/
struct PullRequest : DataType {
 public:
  using id_set_t = std::unordered_set<int_t>;
  using freq_t = uint32_t;
  using id_freq_map_t = std::unordered_map<int_t, freq_t>;

  int is_train = 0;  // 1: train, 0: predict
  std::unordered_set<std::string> tsr_set;
  std::unordered_map<std::string, id_set_t> srm_map;
  id_freq_map_t id_freq_map;

 public:
  void clear() noexcept {
    is_train = 0;
    tsr_set.clear();
    srm_map.clear();
    id_freq_map.clear();
  }

  bool empty() const noexcept {
    return tsr_set.empty() && srm_map.empty() && id_freq_map.empty();
  }
};

OutputStream& operator<<(OutputStream& os, const PullRequest& pull_request);
InputStream& operator>>(InputStream& is, PullRequest& pull_request);

}  // namespace deepx_core