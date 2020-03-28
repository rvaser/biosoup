// Copyright (c) 2020 Robert Vaser

#ifndef BIOSOUP_PROGRESS_BAR_HPP_
#define BIOSOUP_PROGRESS_BAR_HPP_

#include <algorithm>
#include <cstdint>
#include <string>

namespace biosoup {

class ProgressBar {
 public:
  ProgressBar(std::uint32_t num_events, std::uint32_t num_ticks)
      : bar_(std::max(std::min(num_ticks, num_events), 1U), '.'),
        bar_ptr_(0),
        num_events_(num_events),
        event_id_(0),
        events_per_tick_(num_events / static_cast<double>(bar_.size())) {}

  ProgressBar(const ProgressBar&) = default;
  ProgressBar& operator=(const ProgressBar&) = default;

  ProgressBar(ProgressBar&&) = default;
  ProgressBar& operator=(ProgressBar&&) = default;

  ~ProgressBar() = default;

  std::string operator()() {
    ++event_id_;
    if (event_id_ >= num_events_) {
      while (bar_ptr_ < bar_.size()) {
        bar_[bar_ptr_++] = '#';
      }
    } else if (event_id_ >= (bar_ptr_ + 1) * events_per_tick_) {
      bar_[bar_ptr_++] = '#';
    }
    return bar_;
  }

 private:
  std::string bar_;
  std::uint32_t bar_ptr_;
  std::uint32_t num_events_;
  double event_id_;
  double events_per_tick_;
};

}  // namespace biosoup

#endif  // BIOSOUP_PROGRESS_BAR_HPP_
