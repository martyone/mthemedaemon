# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       mthemedaemon

# >> macros
# << macros

Summary:    Shared theme resource loader
Version:    1.0.3
Release:    1
Group:      System/Libraries
License:    LGPLv2.1
URL:        https://github.com/nemomobile/mthemedaemon
Source0:    %{name}-%{version}.tar.bz2
Source1:    mthemedaemon.desktop
Source2:    mthemedaemon.service
Source100:  mthemedaemon.yaml
Requires:   nemo-theme-default
BuildRequires:  pkgconfig(QtOpenGL)
BuildRequires:  pkgconfig(mlite)
BuildRequires:  pkgconfig(systemd)
BuildRequires:  fdupes

%description
Daemon for sharing theme pixmaps


%package testutils
Summary:    Utils for mthemedaemon test packages
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description testutils
This package contains utils for mthemedaemon test packages


%package benchmark-tests
Summary:    Test suite for mthemedaemon - benchmarks
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description benchmark-tests
This package contains benchmark tests for mthemedaemon


%package unit-tests
Summary:    Test suite for mthemedaemon - unit tests
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description unit-tests
This package contains unit tests for mthemedaemon


%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
# << build pre

%qmake 

make %{?jobs:-j%jobs}

# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
# << install pre
%qmake_install
mkdir -p %{buildroot}%{_sysconfdir}/xdg/autostart
cp -a %{SOURCE1} %{buildroot}%{_sysconfdir}/xdg/autostart
mkdir -p %{buildroot}%{_libdir}/systemd/user/
cp -a %{SOURCE2} %{buildroot}%{_libdir}/systemd/user/


# >> install post
# Create the mthemedaemon cache directory
mkdir -p %{buildroot}/var/cache/meegotouch
# << install post

%fdupes  %{buildroot}/%{_datadir}

%postun
# >> postun
if [ -d /var/cache/meegotouch ]; then
rm -rf /var/cache/meegotouch
fi
# << postun

%files
%defattr(-,root,root,-)
%{_bindir}/mthemedaemon
%{_libdir}/systemd/user/mthemedaemon.service
%{_sysconfdir}/xdg/autostart/mthemedaemon.desktop
%{_sysconfdir}/meegotouch/themedaemonpriorities.conf
# >> files
%attr(1777, -, -) /var/cache/meegotouch
# << files

%files testutils
%defattr(-,root,root,-)
/opt/tests/mthemedaemon/libutils.so*
# >> files testutils
# << files testutils

%files benchmark-tests
%defattr(-,root,root,-)
/opt/tests/mthemedaemon/benchmark
/opt/tests/mthemedaemon/benchmark.bin
/opt/tests/mthemedaemon/benchmark-tests.xml
# >> files benchmark-tests
# << files benchmark-tests

%files unit-tests
%defattr(-,root,root,-)
/opt/tests/mthemedaemon/ut_*
/opt/tests/mthemedaemon/stresstest
/opt/tests/mthemedaemon/stresstest.bin
/opt/tests/mthemedaemon/unit-tests.xml
/opt/tests/mthemedaemon/data
# >> files unit-tests
# << files unit-tests
