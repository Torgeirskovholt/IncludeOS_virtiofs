// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
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

#pragma once
#ifndef DISK_DEVICE_HPP
#define DISK_DEVICE_HPP

#include <cstdint>
#include <functional>
#include <memory>

class IDiskDevice
{
public:
  typedef uint64_t block_t;
  
  // To be used by caching mechanism for disk drivers
  typedef std::shared_ptr<void*> buffer;
  
  // Delegate for result of reading a disk sector
  typedef std::function<void(const void*)> on_read_func;
  
  // Read sector(s) from blk and call func with result
  // a null-pointer is passed to result if something bad happened
  virtual void read_sector(block_t blk, on_read_func func) = 0;
  virtual void read_sectors(block_t blk, block_t count, on_read_func) = 0;
  
  // the size of the disk in sectors
  virtual uint64_t size() const = 0;
};

#endif