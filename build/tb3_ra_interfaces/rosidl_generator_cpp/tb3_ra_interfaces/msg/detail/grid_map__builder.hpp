// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice

#ifndef TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__BUILDER_HPP_
#define TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tb3_ra_interfaces/msg/detail/grid_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tb3_ra_interfaces
{

namespace msg
{

namespace builder
{

class Init_GridMap_y_to_go
{
public:
  explicit Init_GridMap_y_to_go(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  ::tb3_ra_interfaces::msg::GridMap y_to_go(::tb3_ra_interfaces::msg::GridMap::_y_to_go_type arg)
  {
    msg_.y_to_go = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_x_to_go
{
public:
  explicit Init_GridMap_x_to_go(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_y_to_go x_to_go(::tb3_ra_interfaces::msg::GridMap::_x_to_go_type arg)
  {
    msg_.x_to_go = std::move(arg);
    return Init_GridMap_y_to_go(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_degree
{
public:
  explicit Init_GridMap_degree(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_x_to_go degree(::tb3_ra_interfaces::msg::GridMap::_degree_type arg)
  {
    msg_.degree = std::move(arg);
    return Init_GridMap_x_to_go(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_weight
{
public:
  explicit Init_GridMap_weight(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_degree weight(::tb3_ra_interfaces::msg::GridMap::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return Init_GridMap_degree(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_y_grid
{
public:
  explicit Init_GridMap_y_grid(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_weight y_grid(::tb3_ra_interfaces::msg::GridMap::_y_grid_type arg)
  {
    msg_.y_grid = std::move(arg);
    return Init_GridMap_weight(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_x_grid
{
public:
  explicit Init_GridMap_x_grid(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_y_grid x_grid(::tb3_ra_interfaces::msg::GridMap::_x_grid_type arg)
  {
    msg_.x_grid = std::move(arg);
    return Init_GridMap_y_grid(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_resolution
{
public:
  explicit Init_GridMap_resolution(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_x_grid resolution(::tb3_ra_interfaces::msg::GridMap::_resolution_type arg)
  {
    msg_.resolution = std::move(arg);
    return Init_GridMap_x_grid(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_heigth
{
public:
  explicit Init_GridMap_heigth(::tb3_ra_interfaces::msg::GridMap & msg)
  : msg_(msg)
  {}
  Init_GridMap_resolution heigth(::tb3_ra_interfaces::msg::GridMap::_heigth_type arg)
  {
    msg_.heigth = std::move(arg);
    return Init_GridMap_resolution(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

class Init_GridMap_width
{
public:
  Init_GridMap_width()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GridMap_heigth width(::tb3_ra_interfaces::msg::GridMap::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_GridMap_heigth(msg_);
  }

private:
  ::tb3_ra_interfaces::msg::GridMap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tb3_ra_interfaces::msg::GridMap>()
{
  return tb3_ra_interfaces::msg::builder::Init_GridMap_width();
}

}  // namespace tb3_ra_interfaces

#endif  // TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__BUILDER_HPP_
