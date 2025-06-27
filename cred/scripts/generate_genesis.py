diff --git a//dev/null b/scripts/generate_genesis.py
index 0000000000000000000000000000000000000000..1c68a95fe81c344b81591d9072516b424452fa46 100644
--- a//dev/null
+++ b/scripts/generate_genesis.py
@@ -0,0 +1,52 @@
+import hashlib
+import struct
+import time
+from dataclasses import dataclass
+
+@dataclass
+class GenesisParams:
+    version: int
+    prev_hash: bytes
+    merkle_root: bytes
+    timestamp: int
+    bits: int
+    reward: int
+
+def double_sha256(data: bytes) -> bytes:
+    return hashlib.sha256(hashlib.sha256(data).digest()).digest()
+
+def target_from_bits(bits: int) -> int:
+    exponent = bits >> 24
+    mantissa = bits & 0xffffff
+    return mantissa * (1 << (8 * (exponent - 3)))
+
+def generate_genesis(params: GenesisParams) -> tuple[int, bytes]:
+    nonce = 0
+    target = target_from_bits(params.bits)
+    while True:
+        header = struct.pack(
+            '<L32s32sLLL',
+            params.version,
+            params.prev_hash,
+            params.merkle_root,
+            params.timestamp,
+            params.bits,
+            nonce,
+        )
+        hash_result = double_sha256(header)[::-1]
+        if int.from_bytes(hash_result, 'big') <= target:
+            return nonce, hash_result
+        nonce += 1
+
+if __name__ == "__main__":
+    params = GenesisParams(
+        version=1,
+        prev_hash=b"\x00" * 32,
+        merkle_root=hashlib.sha256(b"CRED Genesis").digest(),
+        timestamp=int(time.time()),
+        bits=0x1e0ffff0,  # example difficulty target
+        reward=50 * 10**8,  # 50 coins
+    )
+    nonce, block_hash = generate_genesis(params)
+    print(f"Nonce: {nonce}")
+    print(f"Hash: {block_hash.hex()}")
