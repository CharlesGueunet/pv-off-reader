// .NAME OFFReader - Object File Format Reader
// .SECTION Load a .off file into VTK format
// Note: This reader is not able to deal with comment on the file

#pragma once

#include "vtkUnstructuredGridAlgorithm.h"

class OFFReader : public vtkUnstructuredGridAlgorithm
{
public:
  vtkTypeMacro(OFFReader, vtkUnstructuredGridAlgorithm);
  void PrintSelf(ostream &os, vtkIndent indent) override;

  static OFFReader *New();

  // Description:
  // Specify file name of the .abc file.
  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);

protected:
  OFFReader();
  ~OFFReader() = default;

  int RequestData(vtkInformation *,
                  vtkInformationVector **,
                  vtkInformationVector *) override;

private:
  OFFReader(const OFFReader &) = delete;
  void operator=(const OFFReader &) = delete;

  char *FileName;
};
