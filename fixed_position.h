#ifndef _fixed_position_h
#define _fixed_position_h

#include <aspect/particle/integrator/interface.h>

namespace aspect
{
  namespace Particle
  {
    namespace Integrator
    {
      /**
       * A particle integrator that keeps particle coordinates unchanged for the
       * duration of the simulation.
       */
      template <int dim>
      class FixedPosition : public Interface<dim>
      {
        public:
          /**
           * Intentionally leave all particle locations unchanged.
           */
          void
          local_integrate_step(const typename ParticleHandler<dim>::particle_iterator &begin_particle,
                               const typename ParticleHandler<dim>::particle_iterator &end_particle,
                               const std::vector<Tensor<1,dim>> &old_velocities,
                               const std::vector<Tensor<1,dim>> &velocities,
                               const double dt) override;

          /**
           * This integrator does not need any solution vectors because it never
           * updates particle positions.
           */
          std::array<bool, 3>
          required_solution_vectors() const override;

          /**
           * No intermediate storage is necessary.
           */
          static constexpr unsigned int n_integrator_properties = 0;
      };
    }
  }
}

#endif
