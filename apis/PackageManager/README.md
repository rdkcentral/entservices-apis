PackageManager Interfaces

IPackageManager.h is used by the old/existing PackageManager.  After transitioning to the new PackageManager this will be deleted.


Following interfaces in IAppPackageManager.h are used by the New PackageManager
    IPackageDownloader
    IPackageHandler
    IPackageInstaller

IAppPackageConnector.h provides IAppPackageConnector for managing package specifier associations with installed package IDs.
    GetPackageSpecifierRuntimes returns package specifiers and their associated package IDs.
    SetPackageSpecifier associates a package specifier with an installed package ID.

