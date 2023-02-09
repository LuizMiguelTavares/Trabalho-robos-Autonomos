// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tb3_ra_interfaces:msg/GridMap.idl
// generated code does not contain a copyright notice

#ifndef TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__STRUCT_H_
#define TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x_grid'
// Member 'y_grid'
// Member 'weight'
// Member 'degree'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/GridMap in the package tb3_ra_interfaces.
typedef struct tb3_ra_interfaces__msg__GridMap
{
  float width;
  float heigth;
  float resolution;
  rosidl_runtime_c__int32__Sequence x_grid;
  rosidl_runtime_c__int32__Sequence y_grid;
  rosidl_runtime_c__int32__Sequence weight;
  rosidl_runtime_c__float__Sequence degree;
  float x_to_go;
  float y_to_go;
} tb3_ra_interfaces__msg__GridMap;

// Struct for a sequence of tb3_ra_interfaces__msg__GridMap.
typedef struct tb3_ra_interfaces__msg__GridMap__Sequence
{
  tb3_ra_interfaces__msg__GridMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tb3_ra_interfaces__msg__GridMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TB3_RA_INTERFACES__MSG__DETAIL__GRID_MAP__STRUCT_H_
