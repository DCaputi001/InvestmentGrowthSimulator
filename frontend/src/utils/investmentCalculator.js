export class InvestmentAccount {
  constructor(initialAmount, annualInterestRate, monthlyDeposit = 0) {
    this.initialAmount = initialAmount;
    this.annualInterestRate = annualInterestRate;
    this.monthlyDeposit = monthlyDeposit;
  }

  getEndingBalance(numberOfYears) {
    let totalAmount = this.initialAmount;

    if (this.monthlyDeposit > 0) {
      for (let month = 1; month <= numberOfYears * 12; month++) {
        totalAmount += this.monthlyDeposit;
        const monthlyInterest = totalAmount * ((this.annualInterestRate / 100) / 12);
        totalAmount += monthlyInterest;
      }
    } else {
      for (let year = 1; year <= numberOfYears; year++) {
        const yearlyInterest = totalAmount * (this.annualInterestRate / 100);
        totalAmount += yearlyInterest;
      }
    }

    return totalAmount;
  }

  getYearEndInterest(year) {
    const previousBalance = year === 1
      ? this.initialAmount
      : this.getEndingBalance(year - 1);
    const yearEndBalance = this.getEndingBalance(year);
    return yearEndBalance - previousBalance - (this.monthlyDeposit * 12);
  }

  calculateYearlyData(numberOfYears) {
    const yearlyData = [];

    for (let year = 1; year <= numberOfYears; year++) {
      const yearEndBalance = this.getEndingBalance(year);
      const yearEndInterest = this.getYearEndInterest(year);

      yearlyData.push({
        year,
        balance: yearEndBalance,
        interest: yearEndInterest
      });
    }

    return yearlyData;
  }
}
