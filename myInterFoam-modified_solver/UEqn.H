    MRF.correctBoundaryVelocity(U);

    const volVectorField r(mesh.C() - rcDim);

    const volVectorField fict
    (
    - rho*
        (
            2.0*(Omega ^ U)
            + (Omega ^ (Omega ^ r))
            + (dOmegaDt ^ r)
        )
    );

    fvVectorMatrix UEqn
    (
        fvm::ddt(rho, U) + fvm::div(rhoPhi, U)
      + MRF.DDt(rho, U)
      + turbulence->divDevRhoReff(rho, U)
     ==
        fvOptions(rho, U) + fict
    );

    UEqn.relax();

    fvOptions.constrain(UEqn);

    if (pimple.momentumPredictor())
    {
        solve
        (
            UEqn
         ==
            fvc::reconstruct
            (
                (
                    mixture.surfaceTensionForce()
                  - ghf*fvc::snGrad(rho)
                  - fvc::snGrad(p_rgh)
                ) * mesh.magSf()
            )
        );

        fvOptions.correct(U);
    }
