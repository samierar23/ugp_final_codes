{
    const scalar t  = runTime.value();
    const scalar vx = v0*Foam::cos(phi0);
    const scalar vy = v0*Foam::sin(phi0) - gMag*t;
    const scalar v2 = sqr(vx) + sqr(vy);

    const scalar theta   = Foam::atan2(vy, vx);
    const scalar dTheta  = -gMag*vx/v2;
    const scalar ddTheta = -2.0*sqr(gMag)*vx*vy/sqr(v2);

    const scalar c = Foam::cos(theta);
    const scalar s = Foam::sin(theta);
    const tensor A(s, -c, 0,  c, s, 0,  0, 0, 1);

    Omega.value()    = vector(0, 0, dTheta);
    dOmegaDt.value() = vector(0, 0, ddTheta);

    // Free flight: the frame acceleration cancels gravity exactly
    const vector gBody = A & gGround;
    gVec.value() = gBody;

    gh  = (gVec & mesh.C())  - ghRef;
    ghf = (gVec & mesh.Cf()) - ghRef;

    Info<< "t = " << t
        << "  theta = " << theta*180.0/constant::mathematical::pi
        << " deg  gVec = " << gVec.value()
        << "  Omega_z = " << dTheta << endl;
}
