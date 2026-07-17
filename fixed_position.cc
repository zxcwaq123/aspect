#include "fixed_position.h"

namespace aspect
{
  namespace Particle
  {
    namespace Integrator
    {
      template <int dim>
      void
      FixedPosition<dim>::local_integrate_step(const typename ParticleHandler<dim>::particle_iterator & /*begin_particle*/,
                                               const typename ParticleHandler<dim>::particle_iterator & /*end_particle*/,
                                               const std::vector<Tensor<1,dim>> & /*old_velocities*/,
                                               const std::vector<Tensor<1,dim>> & /*velocities*/,
                                               const double /*dt*/)
      {}



      template <int dim>
      std::array<bool, 3>
      FixedPosition<dim>::required_solution_vectors() const
      {
        return {{false, false, false}};
      }
    }
  }
}


namespace aspect
{
  namespace Particle
  {
    namespace Integrator
    {
      ASPECT_REGISTER_PARTICLE_INTEGRATOR(FixedPosition,
                                          "fixed_position",
                                          "A particle integrator that disables particle advection "
                                          "and keeps all particle coordinates fixed.")
    }
  }
}
