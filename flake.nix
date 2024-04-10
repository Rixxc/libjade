{
  description = "Libjade";

  inputs = {
    nixpkgs.url = "nixpkgs/release-23.11";
    easycrypt.url = "github:EasyCrypt/easycrypt?rev=4201fddc14b81d2a69a33f034c9c7db4dfd58d0e";
    jasmin = {
      url = "github:jasmin-lang/jasmin?rev=e84c0c59b4f4e005f2be4de5fdfbcaf1e3e2f975";
      flake = false;
    };
  };

  outputs = { nixpkgs, easycrypt, jasmin, ... }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
      jasminc = pkgs.callPackage "${jasmin}/default.nix" { inherit pkgs; };
      ec = easycrypt.packages.${system}.default;
    in
    {
      packages.${system}.default = pkgs.stdenv.mkDerivation {
        name = "libjade";
        src = ./src;

        nativeBuildInputs = with pkgs; [
          jasminc
          ec
          gcc
          gnumake
        ];

        buildPhase = ''
          make FAIL_ON_ERROR=1 -j$(nproc)
        '';

        installPhase = ''
          mkdir -p $out/lib
          mkdir -p $out/include
          cp libjade.a $out/lib/
          cp libjade.h $out/include/
        '';

      };
    };
}
