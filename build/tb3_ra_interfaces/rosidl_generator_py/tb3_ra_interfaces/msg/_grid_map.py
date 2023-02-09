# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tb3_ra_interfaces:msg/GridMap.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'x_grid'
# Member 'y_grid'
# Member 'weight'
# Member 'degree'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GridMap(type):
    """Metaclass of message 'GridMap'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tb3_ra_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tb3_ra_interfaces.msg.GridMap')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__grid_map
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__grid_map
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__grid_map
            cls._TYPE_SUPPORT = module.type_support_msg__msg__grid_map
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__grid_map

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GridMap(metaclass=Metaclass_GridMap):
    """Message class 'GridMap'."""

    __slots__ = [
        '_width',
        '_heigth',
        '_resolution',
        '_x_grid',
        '_y_grid',
        '_weight',
        '_degree',
        '_x_to_go',
        '_y_to_go',
    ]

    _fields_and_field_types = {
        'width': 'float',
        'heigth': 'float',
        'resolution': 'float',
        'x_grid': 'sequence<int32>',
        'y_grid': 'sequence<int32>',
        'weight': 'sequence<int32>',
        'degree': 'sequence<float>',
        'x_to_go': 'float',
        'y_to_go': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.width = kwargs.get('width', float())
        self.heigth = kwargs.get('heigth', float())
        self.resolution = kwargs.get('resolution', float())
        self.x_grid = array.array('i', kwargs.get('x_grid', []))
        self.y_grid = array.array('i', kwargs.get('y_grid', []))
        self.weight = array.array('i', kwargs.get('weight', []))
        self.degree = array.array('f', kwargs.get('degree', []))
        self.x_to_go = kwargs.get('x_to_go', float())
        self.y_to_go = kwargs.get('y_to_go', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.width != other.width:
            return False
        if self.heigth != other.heigth:
            return False
        if self.resolution != other.resolution:
            return False
        if self.x_grid != other.x_grid:
            return False
        if self.y_grid != other.y_grid:
            return False
        if self.weight != other.weight:
            return False
        if self.degree != other.degree:
            return False
        if self.x_to_go != other.x_to_go:
            return False
        if self.y_to_go != other.y_to_go:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._width = value

    @builtins.property
    def heigth(self):
        """Message field 'heigth'."""
        return self._heigth

    @heigth.setter
    def heigth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heigth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heigth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heigth = value

    @builtins.property
    def resolution(self):
        """Message field 'resolution'."""
        return self._resolution

    @resolution.setter
    def resolution(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'resolution' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'resolution' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._resolution = value

    @builtins.property
    def x_grid(self):
        """Message field 'x_grid'."""
        return self._x_grid

    @x_grid.setter
    def x_grid(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'x_grid' array.array() must have the type code of 'i'"
            self._x_grid = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'x_grid' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._x_grid = array.array('i', value)

    @builtins.property
    def y_grid(self):
        """Message field 'y_grid'."""
        return self._y_grid

    @y_grid.setter
    def y_grid(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'y_grid' array.array() must have the type code of 'i'"
            self._y_grid = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'y_grid' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._y_grid = array.array('i', value)

    @builtins.property
    def weight(self):
        """Message field 'weight'."""
        return self._weight

    @weight.setter
    def weight(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'weight' array.array() must have the type code of 'i'"
            self._weight = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'weight' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._weight = array.array('i', value)

    @builtins.property
    def degree(self):
        """Message field 'degree'."""
        return self._degree

    @degree.setter
    def degree(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'degree' array.array() must have the type code of 'f'"
            self._degree = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'degree' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._degree = array.array('f', value)

    @builtins.property
    def x_to_go(self):
        """Message field 'x_to_go'."""
        return self._x_to_go

    @x_to_go.setter
    def x_to_go(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_to_go' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x_to_go' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x_to_go = value

    @builtins.property
    def y_to_go(self):
        """Message field 'y_to_go'."""
        return self._y_to_go

    @y_to_go.setter
    def y_to_go(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_to_go' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y_to_go' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y_to_go = value
