/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "codedFvOptionTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "fvMatrix.H"

//{{{ begin codeInclude
#line 121 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/capillarySource/vectorCodedSourceCoeffs"
#include "fvCFD.H"
//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 6b7a79372165b0f738cd6579c11a0bb2a673e0e2
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void capillaryRetention_6b7a79372165b0f738cd6579c11a0bb2a673e0e2(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(capillaryRetentionFvOptionvectorSource, 0);
addRemovableToRunTimeSelectionTable
(
    option,
    capillaryRetentionFvOptionvectorSource,
    dictionary
);

} // End namespace fv
} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::fv::
capillaryRetentionFvOptionvectorSource::
capillaryRetentionFvOptionvectorSource
(
    const word& name,
    const word& modelType,
    const dictionary& dict,
    const fvMesh& mesh
)
:
    fv::cellSetOption(name, modelType, dict, mesh)
{
    if (false)
    {
        printMessage("Construct capillaryRetention fvOption from dictionary");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::fv::
capillaryRetentionFvOptionvectorSource::
~capillaryRetentionFvOptionvectorSource()
{
    if (false)
    {
        printMessage("Destroy capillaryRetention");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::fv::
capillaryRetentionFvOptionvectorSource::correct
(
    GeometricField<vector, fvPatchField, volMesh>& fld
)
{
    if (false)
    {
        Info<< "capillaryRetentionFvOptionvectorSource::correct()\n";
    }

//{{{ begin code
    
//}}} end code
}


void
Foam::fv::
capillaryRetentionFvOptionvectorSource::addSup
(
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "capillaryRetentionFvOptionvectorSource::addSup()\n";
    }

//{{{ begin code - warn/fatal if not implemented?
    NotImplemented
//}}} end code
}


void
Foam::fv::
capillaryRetentionFvOptionvectorSource::addSup
(
    const volScalarField& rho,
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "capillaryRetentionFvOptionvectorSource::addSup(rho)\n";
    }

//{{{ begin code - warn/fatal if not implemented?
    #line 134 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/capillarySource/vectorCodedSourceCoeffs"
const fvMesh& mesh = this->mesh();
            const dictionary& c = this->coeffs();

            const volScalarField& alpha =
                mesh.lookupObject<volScalarField>("alpha.electrolyte");

            const scalar rPore  = c.get<scalar>("rPore");
            const scalar sigma  = c.get<scalar>("sigma");
            const scalar theta  =
                c.get<scalar>("contactAngleDeg")
               *constant::mathematical::pi/180.0;

            const scalar Pc = 2.0*sigma*Foam::cos(theta)/rPore;

            const volVectorField gradAlpha(fvc::grad(alpha));

            volVectorField F
            (
                IOobject("capillaryForce", mesh.time().timeName(), mesh),
                mesh,
                dimensionedVector(dimForce/dimVolume, Zero)
            );

            for (const label celli : this->cells())
            {
                F[celli] = -Pc*gradAlpha[celli];
            }

            // "+=" adds a physical source on the right-hand side, independent
            // of the sign convention of eqn.source()
            eqn += F;
//}}} end code
}


void
Foam::fv::
capillaryRetentionFvOptionvectorSource::constrain
(
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "capillaryRetentionFvOptionvectorSource::constrain()\n";
    }

//{{{ begin code
    
//}}} end code
}


// ************************************************************************* //

