diff --git a/README.md b/README.md
index f1b07d1997e84fbf0df35f2f1a61949a960e6321..80d79721f9359fcb16a6e8260b5b0a15c74371d0 100644
--- a/README.md
+++ b/README.md
@@ -1 +1,20 @@
-# CRED
+# CRED
+
+This repository contains the initial tooling for the CRED blockchain.
+
+CRED is a proof-of-work cryptocurrency with custom network parameters. The
+included Python script `scripts/generate_genesis.py` can be used to derive
+a genesis block for test networks or experimentation.
+
+```
+python scripts/generate_genesis.py
+```
+
+The script searches for a nonce that satisfies the difficulty target
+specified within the script and prints the resulting block hash.
+
+## License
+
+This project is released under the MIT License. See the `LICENSE` file for
+details.
+
