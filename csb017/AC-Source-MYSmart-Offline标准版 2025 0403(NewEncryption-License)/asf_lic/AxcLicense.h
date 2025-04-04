#pragma once
#ifndef AX_LIC_EXPORTS
#define AX_LIC_EXPORTS
#endif

/// @brief get remaining days
/// @return remaining days to expire the license
/// 
/// If permanent, it will returns 1000, which is sufficiently large number.
/// 
AX_LIC_EXPORTS int axc_license_days_to_expire();

/// @brief verify the installed license
/// @return (none)
/// 
/// If failed in license verification, critical error dialog will show up and the process will be shut down.
/// 
AX_LIC_EXPORTS void axc_license_verify();

/// @brief check out license
/// @return (none)
/// 
/// It calculates the running time from the last checkout and decreases the remaining time.
/// At every startup, the license manager check-out automatically.
/// If  is recommand to check out at least once a day.
/// 
AX_LIC_EXPORTS void axc_license_check_out();

