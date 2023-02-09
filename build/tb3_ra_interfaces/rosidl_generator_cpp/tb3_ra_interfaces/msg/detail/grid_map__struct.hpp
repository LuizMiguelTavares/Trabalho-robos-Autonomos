// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice

#ifndef TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__STRUCT_HPP_
#define TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tb3_ra_interfaces__msg__GridMap __attribute__((deprecated))
#else
# define DEPRECATED__tb3_ra_interfaces__msg__GridMap __declspec(deprecated)
#endif

namespace tb3_ra_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GridMap_
{
  using Type = GridMap_<ContainerAllocator>;

  explicit GridMap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->width = 0.0f;
      this->heigth = 0.0f;
      this->resolution = 0.0f;
      this->x_to_go = 0.0f;
      this->y_to_go = 0.0f;
    }
  }

  explicit GridMap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->width = 0.0f;
      this->heigth = 0.0f;
      this->resolution = 0.0f;
      this->x_to_go = 0.0f;
      this->y_to_go = 0.0f;
    }
  }

  // field types and members
  using _width_type =
    float;
  _width_type width;
  using _heigth_type =
    float;
  _heigth_type heigth;
  using _resolution_type =
    float;
  _resolution_type resolution;
  using _x_grid_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _x_grid_type x_grid;
  using _y_grid_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _y_grid_type y_grid;
  using _weight_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _weight_type weight;
  using _degree_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _degree_type degree;
  using _x_to_go_type =
    float;
  _x_to_go_type x_to_go;
  using _y_to_go_type =
    float;
  _y_to_go_type y_to_go;

  // setters for named parameter idiom
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__heigth(
    const float & _arg)
  {
    this->heigth = _arg;
    return *this;
  }
  Type & set__resolution(
    const float & _arg)
  {
    this->resolution = _arg;
    return *this;
  }
  Type & set__x_grid(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->x_grid = _arg;
    return *this;
  }
  Type & set__y_grid(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->y_grid = _arg;
    return *this;
  }
  Type & set__weight(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->weight = _arg;
    return *this;
  }
  Type & set__degree(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->degree = _arg;
    return *this;
  }
  Type & set__x_to_go(
    const float & _arg)
  {
    this->x_to_go = _arg;
    return *this;
  }
  Type & set__y_to_go(
    const float & _arg)
  {
    this->y_to_go = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tb3_ra_interfaces::msg::GridMap_<ContainerAllocator> *;
  using ConstRawPtr =
    const tb3_ra_interfaces::msg::GridMap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tb3_ra_interfaces::msg::GridMap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tb3_ra_interfaces::msg::GridMap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tb3_ra_interfaces__msg__GridMap
    std::shared_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tb3_ra_interfaces__msg__GridMap
    std::shared_ptr<tb3_ra_interfaces::msg::GridMap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GridMap_ & other) const
  {
    if (this->width != other.width) {
      return false;
    }
    if (this->heigth != other.heigth) {
      return false;
    }
    if (this->resolution != other.resolution) {
      return false;
    }
    if (this->x_grid != other.x_grid) {
      return false;
    }
    if (this->y_grid != other.y_grid) {
      return false;
    }
    if (this->weight != other.weight) {
      return false;
    }
    if (this->degree != other.degree) {
      return false;
    }
    if (this->x_to_go != other.x_to_go) {
      return false;
    }
    if (this->y_to_go != other.y_to_go) {
      return false;
    }
    return true;
  }
  bool operator!=(const GridMap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GridMap_

// alias to use template instance with default allocator
using GridMap =
  tb3_ra_interfaces::msg::GridMap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tb3_ra_interfaces

#endif  // TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__STRUCT_HPP_
