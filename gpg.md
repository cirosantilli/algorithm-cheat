# GPG

GNU Private Guard encryption.

Encrypt data and verify identities through algorithms sch as RSA.

Interface based on the 1991 commercial Pretty Good Privacy (PGP). The interface has been open sourced as `OpenPGP`.

## Public key encryption

You have to understand the very basics of asymmetric encryption such as RSA before reading this.

### Quickstart

#### Recipient receive

    gpg --gen-key

Sample output:

    pub   1234R/12345678 2000-01-01
        Key fingerprint = AAAA AAAA AAAA AAAA AAAA  AAAA AAAA AAAA AAAA AAAA
    uid                  user <email>
    sub   1234R/87654321 2000-01-01

So the key ID is `01234567`.

    gpg -a --export 01234567 >key.asc

Post `key.asc` on your homepage where everyone can see it.

If you are serious about it, find a Certificate Authority, and register. There are even free ones like: <http://www.cacert.org/> They take your passport, and associate your personal data to your key.

#### Message sender

Get the `key.asc` from the receiver.

Say that you trust the key:

    gpg --import key.asc

Sample output:

    gpg: key 5147EA06: public key "Ciro Santilli <ciro.santilli.contact@gmail.com>" imported
    gpg: Total number processed: 1
    gpg:               imported: 1  (RSA: 1)

Encrypt your message:

    echo 'Hello world!' >'message.txt"
    gpg -e 'message.txt' -r "5147EA06"

This generates an encrypted `message.txt.gpg` file. `hd message.txt.gpg` confirms that our message is nowhere to be seen.

Send that file to the recipient.

#### Recipient decrypt

    gpg -d message.txt.gpg

Sample output:

    gpg: encrypted with 2048-bit RSA key, ID 73853219, created 2015-05-30
        "Ciro Santilli <ciro.santilli.contact@gmail.com>"
    Hello world!

You can only decrypt that of course if you have the private key that corresponds to the public key used to encrypt.

### Create a key

### gen-key

Generate pub/private pair:

    gpg --gen-key

You will be prompted for several parameters of the key.

The generated key goes under `GNUPGHOME`.

The output of the command is the same as that of the `--fingerprint` command.

#### Files

#### GNUPGHOME

Place where GPG stores information like private and public keys

 `~/.gnupg` by default.

Stored under `~/gnupg/`:

- `gpg.conf`: every line in that file is passed on the command line. Only the long form of options can be used, without the two trailing slashes, e.g.: `keyserver hkp://keys.gnupg.net` is equivalent to `--keyserver hkp://keys.gnupg.net`
- `secring.gpg`: private keys. **NEVER SHARE THIS FILE**.
- `pubring.gpg`: public keys. This is what you will share with others.
- `trustdb.gpg`: keys that you trust.

Each key file (`.asc` or `.gpg`) may contain many keys.

In each key, name and email are visible in plain text! So whenever you give your public key away, that information is directly available. <http://security.stackexchange.com/questions/25170/what-information-is-leaked-from-an-openpgp-encrypted-file>

##### asc

`.asc` extension is used for ASCII key files.

It is of the form:

    -----BEGIN PGP PUBLIC KEY BLOCK-----
    Version: GnuPG v1

    mQENBFVphJABCADLime1j/dqpxGoN8fF3HFpWRnQnDkmw1MHCQMsRDPkgpB/N09s
    [[ more lines ]]
    Y94TNP+YCcaPtC+CanR3ItQ4ncmxDoP9Ep4NOGyfDPT+mfCG1QyF3pp/kLuesA==
    =nAyn
    -----END PGP PUBLIC KEY BLOCK-----

the middle of the file:

    mQENBFVphJABCADLime1j/dqpxGoN8fF3HFpWRnQnDkmw1MHCQMsRDPkgpB/N09s
    [[ more lines ]]
    Y94TNP+YCcaPtC+CanR3ItQ4ncmxDoP9Ep4NOGyfDPT+mfCG1QyF3pp/kLuesA==

is a direct Base64 encoding of the binary raw data.

`-a` stands for "ASCII armor", which is the GPG jargon for ASCII encode.

### import

Import a public key someone else exported:

    gpg --import key.asc

### k

### list-keys

List public keys:

    gpg -k

Sample output:

    /home/you/.gnupg/pubring.gpg
    -----------------------------
    pub   2048R/12345678 2000-01-01
    uid                  Your Name <you@mail.com>
    sub   2048R/87654321 2000-01-01

Meaning of fields: TODO

- `pub`: public key
- `sub`: subkey for corresponding public key
- `2048R`: type of key, here 2048-bit RSA
- `12345678`: local key id, `name` in the manual

### list-secret-keys

Like `list-keys`, but for private keys.

#### Subkey

There can be multiple subkeys per pub key.

Application: <http://blog.dest-unreach.be/wp-content/uploads/2009/04/pgp-subkeys.html>

You can revoke subkeys if you have the master key, without revoking the master key.

You can generate a new subkey from the master key, and keep your identity.

The common usage patter is to:

- keep the master key *very* safe, e.g. cold storage
- keep the subkey in your laptop for daily use

Then if you ever notice that your subkey has been hacked, take the master key from cold storage, use it once to revoke the subkey and generate a new one. It will still be possible for third parties to verify that you are you.

### fingerprint

    gpg --fingerprint

Same as `list-keys`, but also show key fingerprints.

Fingerprints are hashes of keys, used to identify them uniquely.

Sample output:

    /home/you/.gnupg/pubring.gpg
    -----------------------------
    pub   1234R/12345678 2000-01-01
        Key fingerprint = AAAA AAAA AAAA AAAA AAAA  AAAA AAAA AAAA AAAA AAAA
    uid                  user <email>
    sub   1234R/87654321 2000-01-01

Can also be used as a unique key identifier, e.g.:

    gpg --export 'AAAA AAAA AAAA AAAA AAAA  AAAA AAAA AAAA AAAA AAAA'

#### Get fingerprint without importing key

    gpg --with-fingerprint a.asc

### export

Export a key in binary format:

    gpg --export "$KEY_ID"

Export in ASCII encoded format:

    gpg -a --export "$KEY_ID"

which generates an `.asc` format file.

### KEY_ID

### Key id

A key can be identified in the following ways:

- it's local ID obtained with `--list-keys`
- it's fingerprint, obtained with `--fingerprint`

### dearmor

Convert ASCII key format to binary:

    gpg --dearmor 'a.asc'

Generates a `a.asc.gpg` file.

### enarmor

Opposite of `dearmor`.

    gpg --enarmor 'a.asc.gpg'

### edit-key

Add extra information to keys:

    gpg --edit-key you@mail.com

This opens up a REPL interface.

#### addphoto

Add a picture to your key:

    addphoto

Should be a very small (32x32) JPEG.

Now `--list-keys` says:

    pub   1234R/12345678 2000-01-01
    uid                  Your Name <you@mail.com>
    uid                  [jpeg image of size 783]
    sub   1234R/87654321 2000-01-01

TODO how to see this photo later?

---

Add pubkey to the trust list:

    gpg --import

Remove public key:

    gpg --delete-key "$KEY_ID"

If you have they corresponding private key, GPG will require you to delete the private first:

    gpg --delete-secret-keys "$KEY_ID"

### Encrypt and decrypt

Create a `"$MESSAGE_FILE.gpg"` pubkey encrypted file:

    gpg -r "$KEY_ID" -e "$MESSAGE_FILE"

You must have previously imported the `KEY_ID`:

- <http://unix.stackexchange.com/questions/104941/is-there-a-way-to-embed-a-gpg-public-key-in-a-script-without-adding-it-to-the-ke>
- <http://stackoverflow.com/questions/9073288/decrypt-encrypted-gpg-file-using-external-secret-key>
- <http://lists.gnupg.org/pipermail/gnupg-users/2004-October/023409.html>

Only the person who knows the corresponding private key will be able to decrypt it.

Decrypt file for which you own the private key:

    gpg -e "$MESSAGE_FILE.gpg"

### Verify file

Create a `"$MESSAGE_FILE"` verification file:

    gpg -ab "$MESSAGE_FILE"

Verify file with its verification file:

    gpg --verify "$MESSAGE_FILE.asc" "$MESSAGE_FILE"

Only works of course if the key is in you keyring.

### clearsign

Analogous to signing a document, scanning and uploading it:

- you assert that you have read it and agree to its terms
- anyone can see the document

Usage:

    gpg --clearsign UbuntuCodeofConduct-2.0.txt
    cat UbuntuCodeofConduct-2.0.txt.asc

Sample output:

    -----BEGIN PGP SIGNED MESSAGE-----
    Hash: SHA1

    <THE MESSAGE>
    -----BEGIN PGP SIGNATURE-----
    Version: GnuPG v1.4.11 (GNU/Linux)

    <BASE64 signature data>
    -----END PGP SIGNATURE-----

### Publish you pubkey

So that others can:

- encrypt stuff so that you can read it.
- verify you are the creator of files.

As binary:

    gpg -o a.gpg --export "$UID"

This could be sent on an email attachment.

As ASCII:

    gpg -a -o a.gpg --export "$UID"

This could be sent on an email body or as an attachment.

View keys in a key file (`.asc` or `.gpg`):

    gpg a.gpg

#### keyserver

The best method to publish your pubkey. People only have to know your keyserver, and they can look for your key themselves.

Of course, nothing prevents you from signing as `Bill Gates`, and then you need some way to prove that that is your real identity.

Well known servers:

    # On the default gpg.conf file
    KEYSERVER='hkp://keys.gnupg.net'

    KEYSERVER='http://pgp.mit.edu'
    KEYSERVER='hkp://keyserver.ubuntu.com'
    KEYSERVER='https://keyserver.pgp.com'

You don't even need to create an account there to add your key:

    gpg  --keyserver "$KEYSERVER" --send-keys "$KEY_ID"

You need to use the key id, not the user id, since one user can have many keys.

Search for someone's key on a server:

    gpg --search-keys "$UID" --keyserver "$KEYSERVER"
    gpg --search-keys "C123 E5F2 C15C 4F35 486E 56D5 1DD2 ED17 5A56 E42E"

### Multiple servers

Not possible: <http://www.gossamer-threads.com/lists/gnupg/users/14754>

If you pass multiple `--options` flags, the last one wins.

### hkp protocol

HTTP Keyserver Protocol (HKP), used for example to publish keys.

## Symmetric encryption

## Password only encryption

The least interesting method.

Create a `"$MESSAGE_FILE.gpg"` password-only encrypted file:

    gpg -c "$MESSAGE_FILE"

This asks your your password. After you enter it, the message is shown on the stdout.

Good combo with `tar.gz`.

Create from stdin:

    gpg -o "$MESSAGE_FILE.gpg" -c <"$MESSAGE_FILE"

Decrypt to MESSAGE_FILE:

    gpg "$MESSAGE_FILE.gpg"

Decrypt to stdout:

    gpg -d "$MESSAGE_FILE.gpg"

Decrypts to MESSAGE_FILE:

    gpg -o "$MESSAGE_FILE" -d "$MESSAGE_FILE.gpg"

Decrypt from stdin:

    cat "$MESSAGE_FILE.gpg" | gpg -o "$MESSAGE_FILE" -d

## Bibliography

- <https://www.gnupg.org/gph/en/manual.html>
- <https://alexcabal.com/creating-the-perfect-gpg-keypair/>
- <http://www.spywarewarrior.com/uiuc/gpg/gpg-com-4.htm>
- <http://www.madboa.com/geek/gpg-quickstart/>
- <https://help.ubuntu.com/community/GnuPrivacyGuardHowto>
- <http://irtfweb.ifa.hawaii.edu/~lockhart/gpg/>
