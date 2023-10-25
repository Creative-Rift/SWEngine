/// @file glm/ext.hpp
///
/// @ref core (Dependence)
/// 
/// @defgroup gtc GTC Extensions (Stable)
///
/// @brief Functions and types that the GLSL specification doesn't define, but useful to have for a C++ program.
/// 
/// GTC extensions aim to be stable. 
/// 
/// Even if it's highly unrecommended, it's possible to include all the extensions at once by
/// including <glm/ext.hpp>. Otherwise, each extension needs to be included  a specific file.
/// 
/// @defgroup gtx GTX Extensions (Experimental)
/// 
/// @brief Functions and types that the GLSL specification doesn't define, but 
/// useful to have for a C++ program.
/// 
/// Experimental extensions are useful functions and types, but the development of
/// their API and functionality is not necessarily stable. They can change 
/// substantially between versions. Backwards compatibility is not much of an issue
/// for them.
/// 
/// Even if it's highly unrecommended, it's possible to include all the extensions 
/// at once by including <glm/ext.hpp>. Otherwise, each extension needs to be 
/// included  a specific file.

#pragma once

#include "glm.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_MESSAGE_EXT_INCLUDED_DISPLAYED)
#	define GLM_MESSAGE_EXT_INCLUDED_DISPLAYED
#	pragma message("GLM: All extensions included (not recommanded)")
#endif//GLM_MESSAGES

#include "glm/gtc/bitfield.hpp"
#include "glm/gtc/color_space.hpp"
#include "glm/gtc/constants.hpp"
#include "glm/gtc/epsilon.hpp"
#include "glm/gtc/functions.hpp"
#include "glm/gtc/integer.hpp"
#include "glm/gtc/matrix_access.hpp"
#include "glm/gtc/matrix_integer.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/noise.hpp"
#include "glm/gtc/packing.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/random.hpp"
#include "glm/gtc/reciprocal.hpp"
#include "glm/gtc/round.hpp"
//#include "./gtc/type_aligned.hpp"
#include "glm/gtc/type_precision.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/ulp.hpp"
#include "glm/gtc/vec1.hpp"
#if GLM_HAS_ALIGNED_TYPE
#	include "glm/gtc/type_aligned.hpp"
#endif

#include "glm/gtx/associated_min_max.hpp"
#include "glm/gtx/bit.hpp"
#include "glm/gtx/closest_point.hpp"
#include "glm/gtx/color_space.hpp"
#include "glm/gtx/color_space_YCoCg.hpp"
#include "glm/gtx/compatibility.hpp"
#include "glm/gtx/component_wise.hpp"
#include "glm/gtx/dual_quaternion.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/extend.hpp"
#include "glm/gtx/extended_min_max.hpp"
#include "glm/gtx/fast_exponential.hpp"
#include "glm/gtx/fast_square_root.hpp"
#include "glm/gtx/fast_trigonometry.hpp"
#include "glm/gtx/gradient_paint.hpp"
#include "glm/gtx/handed_coordinate_space.hpp"
#include "glm/gtx/integer.hpp"
#include "glm/gtx/intersect.hpp"
#include "glm/gtx/log_base.hpp"
#include "glm/gtx/matrix_cross_product.hpp"
#include "glm/gtx/matrix_interpolation.hpp"
#include "glm/gtx/matrix_major_storage.hpp"
#include "glm/gtx/matrix_operation.hpp"
#include "glm/gtx/matrix_query.hpp"
#include "glm/gtx/mixed_product.hpp"
#include "glm/gtx/norm.hpp"
#include "glm/gtx/normal.hpp"
#include "glm/gtx/normalize_dot.hpp"
#include "glm/gtx/number_precision.hpp"
#include "glm/gtx/optimum_pow.hpp"
#include "glm/gtx/orthonormalize.hpp"
#include "glm/gtx/perpendicular.hpp"
#include "glm/gtx/polar_coordinates.hpp"
#include "glm/gtx/projection.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/raw_data.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "glm/gtx/spline.hpp"
#include "glm/gtx/std_based_type.hpp"

#if !(GLM_COMPILER & GLM_COMPILER_CUDA)
#	include "glm/gtx/string_cast.hpp"
#endif

#include "glm/gtx/transform.hpp"
#include "glm/gtx/transform2.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "glm/gtx/vector_query.hpp"
#include "glm/gtx/wrap.hpp"

#if GLM_HAS_TEMPLATE_ALIASES
#	include "glm/gtx/scalar_multiplication.hpp"
#endif

#if GLM_HAS_RANGE_FOR
#	include "glm/gtx/range.hpp"
#endif
