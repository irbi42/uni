SET EMACS=emacs-24.3
SET SLIME=slime-2013-12-18
SET SBCL=Steel Bank Common Lisp\1.1.12

SET HOME=%CD%
SET APPDATA=%CD%\AppData
SET LOCALAPPDATA=%CD%\AppData\Local
SET SBCL_HOME=%CD%\%SBCL%\
SET PATH=%SBCL_HOME%\;%PATH%

%CD%\%EMACS%\bin\runemacs.exe -Q --load  %CD%\.emacs --directory %CD%/%SLIME%/
