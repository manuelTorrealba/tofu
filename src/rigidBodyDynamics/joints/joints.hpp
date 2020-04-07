// Null joint for the root-body
#include "rigidBodyDynamics/joints/null/nullJoint.hpp"

// Composite joint to handle combination of rotations and translations
#include "rigidBodyDynamics/joints/composite/compositeJoint.hpp"

// 6-DoF joint for floating bodies
#include "rigidBodyDynamics/joints/floating/floatingJoint.hpp"

// Revolute joints
#include "rigidBodyDynamics/joints/Rx/Rx.hpp"
#include "rigidBodyDynamics/joints/Ry/Ry.hpp"
#include "rigidBodyDynamics/joints/Rz/Rz.hpp"
#include "rigidBodyDynamics/joints/Ra/Ra.hpp"
#include "rigidBodyDynamics/joints/Rs/Rs.hpp"
#include "rigidBodyDynamics/joints/Rzyx/Rzyx.hpp"
#include "rigidBodyDynamics/joints/Rxyz/Rxyz.hpp"
#include "rigidBodyDynamics/joints/Ryxz/Ryxz.hpp"

// Prismatic joints
#include "rigidBodyDynamics/joints/Px/Px.hpp"
#include "rigidBodyDynamics/joints/Py/Py.hpp"
#include "rigidBodyDynamics/joints/Pz/Pz.hpp"
#include "rigidBodyDynamics/joints/Pa/Pa.hpp"
#include "rigidBodyDynamics/joints/Pxyz/Pxyz.hpp"

// 0-DoF joints
#include "rigidBodyDynamics/joints/rigid/rigid.hpp"
#include "rigidBodyDynamics/joints/function/function.hpp"
#include "rigidBodyDynamics/joints/functionDot/functionDot.hpp"
