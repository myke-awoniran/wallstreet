# Trading Simulator (Order Book Engine)

A high-performance **limit order book (LOB)** and **matching engine simulator** for crypto-style markets, built for
learning market microstructure, replaying historical data, and experimenting with matching algorithms.

This project simulates how exchanges process **bids**, **asks**, and **order matching**, producing trades, updated
books, and market data outputs from raw CSV tick/order updates.

---

## Features

### Core Engine

- Limit Order Book (L2 / price-level book)
- Supports bids and asks
- Maintains best prices: best bid, best ask, spread, midprice
- Realistic price-time priority (FIFO at each price level)

### Matching

- Matching algorithm:
    - Buy orders match lowest available ask levels first
    - Sell orders match highest available bid levels first
- Partial fills
- Full fills
- Generates trades (price, quantity, taker side, timestamp)
- Produces order book events (add/cancel/modify/fill)

### Simulation / Replay

- Replay CSV streams to rebuild and simulate the market
- Supports crypto-style data fields like:

  ```csv
  2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869