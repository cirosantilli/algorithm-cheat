# Bitcoin

<http://en.wikipedia.org/wiki/Bitcoin>

## Sources

-   <http://www.michaelnielsen.org/ddi/how-the-bitcoin-protocol-actually-works/>

-   <http://www.righto.com/2014/02/bitcoins-hard-way-using-raw-bitcoin.html>

    <http://www.righto.com/2014/02/bitcoin-mining-hard-way-algorithms.html>

    <http://www.righto.com/2014/02/bitcoin-transaction-malleability.html>

## Alternatives

Bitcoin is the most popular one today, but there are others:

- <http://en.wikipedia.org/wiki/Litecoin>
- <http://en.wikipedia.org/wiki/Ripple_%28payment_protocol%29>

## Specification

Bitcoin is a protocol.

TODO There seems to be no specification besides the source of the original implementation?

- <https://en.bitcoin.it/wiki/Protocol_specification> seems to be a high level view of the source, and as close as it gets to a standard. TODO who can edit that?

- <http://www.michaelnielsen.org/ddi/how-the-bitcoin-protocol-actually-works/> is a good intro, but starts too verbose. Jump directly to the "Bitcoin" section.

## General concepts

There is no centralized entity that verifies the money. That is why anarchists like Bitcoin. And why it's more efficient and makes part of baking useless.

If a transaction is done, everyone knows it, can attach it to an user ID, and where the money come from. This is interesting as it puts trust on everyone's eyes instead of that of a bank.

The question is of course who is behind the hash ID.

There is no entity that corresponds to a single bitcoin: only transactions. When you send a bitcoin, you are making a transaction, and saying from which other transaction the money comes from.

### Ledger

<http://en.wikipedia.org/wiki/Ledger>

## Specification Overview

This supposes you know what SHA-256 does.

### Transaction format

Data is JSON encoded as follows (with abbreviated hex SHA-256 hashes):

    {
        "hash": "7c4025...",
        "ver": 1,
        "vin_sz": 1,
        "vout_sz": 1,
        "lock_time": 0,
        "size": 224,
        "in": [
            {
                "prev_out": {
                    "hash": "2007ae...",
                    "n": 0
                },
                "scriptSig": "304502... 042b2d..."
            }
        ],
        "out": [
            {
                "value": "0.31900000",
                "scriptPubKey": "OP_DUP OP_HASH160 a7db6f... OP_EQUALVERIFY OP_CHECKSIG"
            }
        ]
    }

Where:

-   `hash`: hash of the rest of the transaction. This is the ID of the transaction.

-   `ver`: protocol version. The only one so far is `1`.

-   `vin_sz`, `vout_sz`: number of inputs and outputs. This transaction has one of each, but more are possible. TODO.

-   `lock_time`: `0` is the most common. TODO.

-   `size`: length in bytes of the data that follows

-   `in`:

    List of transactions from which the money to be transfered comes from: every sent bitcoin comes from an older transaction.

    Their valued is summed. Each input comes from an older transaction.

    -   `prev_out`:

        - `hash`: hash of the transcation the money for this transaction comes from
        - `n`: the number of output of that transacation that the money comes from, in this case the first, `0`

        If you backtrack more and more, you will reach either of:

        - <https://en.bitcoin.it/wiki/Genesis_block> which was necessary to start up the system, and must be treated specially.
        - coinbase transaction (huge majority), which were bitcoins generated as miner rewards

    - `scriptSig`:

        - `304502`: TODO
        - `042b2d`: TODO

-   `out`:

    -   `value`: value being sent

        The sum of the output values of the input transactions must be equal or greater than this.

        If greater, the remainder goes to the miner who verified the transaction. TODO rationale?

        To avoid losing money this way, you can create a transaction with 2 outputs:

        - the real target with the correct address
        - yourself for the rest

    -   `scriptPubKey`:

        - `a7db6f`: destination address

You can trace transactions back

### Peer finding

<http://bitcoin.stackexchange.com/questions/3536/how-do-bitcoin-clients-find-each-other>

<https://en.bitcoin.it/wiki/Satoshi_Client_Node_Discovery>

Peers are generally found through other peers.

For the first connection, known domains are used.

### Mining

### Transaction verification

TODO

## Scripting

Bitcoin has a [stack based scripting language](http://en.wikipedia.org/wiki/Stack-oriented_programming_language) built-in, but it is purposefully not Turing complete as it does not have loops to prevent DoS.

TODO how does it work exactly?

## Implementations

Bitcoin core is the reference implementation by the core developers.

## Tools

- <http://blockexplorer.com/> web UI for viewing bitcoin information

## Trivia

-   <http://en.wikipedia.org/wiki/Satoshi_Nakamoto>

    The mysterious creator(s) of bitcoin.

-   <http://en.wikipedia.org/wiki/Mt._Gox>

    Originally the domain and software were used for Magic the Gathering trading: it stands for `MtG Onlilne eXchange`.

    Interesting how that was converted to become a bitcoin trading pole.

-   <http://en.wikipedia.org/wiki/Winklevoss_twins>

    After being involved with Facebook lawsuits winning 65M, they still went to the 2008 Olympics in China and in 2014 own 1% of the bitcoins! How many crazy things can you do in a lifetime?

-   <http://www.coindesk.com/194993-btc-transaction-147m-mystery-and-speculation>

    The largest bitcoin transaction so far, worth 150M at the time.

    Commentators noted how such a transaction in regular currencies would be a logistic nightmare to make, while with Bitcoin it comes down to setting the value of an integer.

-   <https://en.bitcoin.it/wiki/Laszlo%27s_pizza>

-   <http://panampost.com/belen-marty/2014/10/07/couple-make-history-with-worlds-first-bitcoin-wedding/>

-   Bitcoin based proof of knowledge at a given time without revealing it:

    - <https://www.btproof.com/>
    - <http://www.proofofexistence.com/>

-   <http://en.wikipedia.org/wiki/SatoshiDice>

    Bitcoin gambling website. Sold for 12M in 2013.

-   You can store arbitrary data on the blockchain.

    Small selection of amusing ones:

    <http://www.righto.com/2014/02/ascii-bernanke-wikileaks-photographs.html>
