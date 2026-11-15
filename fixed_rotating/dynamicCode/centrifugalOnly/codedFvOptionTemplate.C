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
#line 56 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/rotatingFrameSource/vectorCodedSourceCoeffs"
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
// SHA1 = 1246ee7854bbd15a17cddb67cd76863ecf39bcf4
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void centrifugalOnly_1246ee7854bbd15a17cddb67cd76863ecf39bcf4(bool load)
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

defineTypeNameAndDebug(centrifugalOnlyFvOptionvectorSource, 0);
addRemovableToRunTimeSelectionTable
(
    option,
    centrifugalOnlyFvOptionvectorSource,
    dictionary
);

} // End namespace fv
} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::fv::
centrifugalOnlyFvOptionvectorSource::
centrifugalOnlyFvOptionvectorSource
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
        printMessage("Construct centrifugalOnly fvOption from dictionary");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::fv::
centrifugalOnlyFvOptionvectorSource::
~centrifugalOnlyFvOptionvectorSource()
{
    if (false)
    {
        printMessage("Destroy centrifugalOnly");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::fv::
centrifugalOnlyFvOptionvectorSource::correct
(
    GeometricField<vector, fvPatchField, volMesh>& fld
)
{
    if (false)
    {
        Info<< "centrifugalOnlyFvOptionvectorSource::correct()\n";
    }

//{{{ begin code
    #line 61 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/rotatingFrameSource/vectorCodedSourceCoeffs"
// not used
//}}} end code
}


void
Foam::fv::
centrifugalOnlyFvOptionvectorSource::addSup
(
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "centrifugalOnlyFvOptionvectorSource::addSup()\n";
    }

//{{{ begin code - warn/fatal if not implemented?
    #line 66 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/rotatingFrameSource/vectorCodedSourceCoeffs"
// not called - rho-weighted overload used instead
//}}} end code
}


void
Foam::fv::
centrifugalOnlyFvOptionvectorSource::addSup
(
    const volScalarField& rho,
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "centrifugalOnlyFvOptionvectorSource::addSup(rho)\n";
    }

//{{{ begin code - warn/fatal if not implemented?
    #line 71 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/rotatingFrameSource/vectorCodedSourceCoeffs"
const fvMesh& mesh = this->mesh();

            const scalar omega = 104.72;
            const vector origin(0.0125, 0, 0);
            const vector axis(0, 1, 0);
            const vector Om = omega*axis;

            volVectorField F
            (
        	IOobject("centrifugalForce", mesh.time().timeName(), mesh),
        	mesh,
        	dimensionedVector(dimForce/dimVolume, Zero)
    	    );

            for (const label celli : this->cells())
            {
                const vector r = mesh.C()[celli] - origin;
                const vector centrifugal = -(Om ^ (Om ^ r));
                F[celli] += rho[celli]*centrifugal;
            }

            eqn += F;
//}}} end code
}


void
Foam::fv::
centrifugalOnlyFvOptionvectorSource::constrain
(
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<< "centrifugalOnlyFvOptionvectorSource::constrain()\n";
    }

//{{{ begin code
    #line 98 "/home/samiera/OpenFOAM/samiera-v2512/run/final_codes/interFoam/constant/fvOptions/rotatingFrameSource/vectorCodedSourceCoeffs"
// not used
//}}} end code
}


// ************************************************************************* //

