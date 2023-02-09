// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice

#ifndef TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__TRAITS_HPP_
#define TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tb3_ra_interfaces/msg/detail/grid_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tb3_ra_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GridMap & msg,
  std::ostream & out)
{
  out << "{";
  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: heigth
  {
    out << "heigth: ";
    rosidl_generator_traits::value_to_yaml(msg.heigth, out);
    out << ", ";
  }

  // member: resolution
  {
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << ", ";
  }

  // member: x_grid
  {
    if (msg.x_grid.size() == 0) {
      out << "x_grid: []";
    } else {
      out << "x_grid: [";
      size_t pending_items = msg.x_grid.size();
      for (auto item : msg.x_grid) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y_grid
  {
    if (msg.y_grid.size() == 0) {
      out << "y_grid: []";
    } else {
      out << "y_grid: [";
      size_t pending_items = msg.y_grid.size();
      for (auto item : msg.y_grid) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: weight
  {
    if (msg.weight.size() == 0) {
      out << "weight: []";
    } else {
      out << "weight: [";
      size_t pending_items = msg.weight.size();
      for (auto item : msg.weight) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: degree
  {
    if (msg.degree.size() == 0) {
      out << "degree: []";
    } else {
      out << "degree: [";
      size_t pending_items = msg.degree.size();
      for (auto item : msg.degree) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x_to_go
  {
    out << "x_to_go: ";
    rosidl_generator_traits::value_to_yaml(msg.x_to_go, out);
    out << ", ";
  }

  // member: y_to_go
  {
    out << "y_to_go: ";
    rosidl_generator_traits::value_to_yaml(msg.y_to_go, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GridMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: heigth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heigth: ";
    rosidl_generator_traits::value_to_yaml(msg.heigth, out);
    out << "\n";
  }

  // member: resolution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << "\n";
  }

  // member: x_grid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x_grid.size() == 0) {
      out << "x_grid: []\n";
    } else {
      out << "x_grid:\n";
      for (auto item : msg.x_grid) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y_grid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y_grid.size() == 0) {
      out << "y_grid: []\n";
    } else {
      out << "y_grid:\n";
      for (auto item : msg.y_grid) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.weight.size() == 0) {
      out << "weight: []\n";
    } else {
      out << "weight:\n";
      for (auto item : msg.weight) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: degree
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.degree.size() == 0) {
      out << "degree: []\n";
    } else {
      out << "degree:\n";
      for (auto item : msg.degree) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x_to_go
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_to_go: ";
    rosidl_generator_traits::value_to_yaml(msg.x_to_go, out);
    out << "\n";
  }

  // member: y_to_go
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_to_go: ";
    rosidl_generator_traits::value_to_yaml(msg.y_to_go, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GridMap & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tb3_ra_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tb3_ra_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tb3_ra_interfaces::msg::GridMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  tb3_ra_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tb3_ra_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tb3_ra_interfaces::msg::GridMap & msg)
{
  return tb3_ra_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tb3_ra_interfaces::msg::GridMap>()
{
  return "tb3_ra_interfaces::msg::GridMap";
}

template<>
inline const char * name<tb3_ra_interfaces::msg::GridMap>()
{
  return "tb3_ra_interfaces/msg/GridMap";
}

template<>
struct has_fixed_size<tb3_ra_interfaces::msg::GridMap>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tb3_ra_interfaces::msg::GridMap>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tb3_ra_interfaces::msg::GridMap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__TRAITS_HPP_
