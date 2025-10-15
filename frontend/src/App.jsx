import { useState } from 'react';
import InputForm from './components/InputForm';
import ResultsTable from './components/ResultsTable';
import { InvestmentAccount } from './utils/investmentCalculator';
import './App.css';

function App() {
  const [results, setResults] = useState(null);

  const handleCalculate = (data) => {
    const accountWithoutDeposit = new InvestmentAccount(
      data.initialInvestment,
      data.annualInterest
    );

    const accountWithDeposit = new InvestmentAccount(
      data.initialInvestment,
      data.annualInterest,
      data.monthlyDeposit
    );

    const withoutDepositData = accountWithoutDeposit.calculateYearlyData(data.years);
    const withDepositData = accountWithDeposit.calculateYearlyData(data.years);

    setResults({
      withoutDeposit: withoutDepositData,
      withDeposit: withDepositData,
      monthlyDeposit: data.monthlyDeposit
    });
  };

  return (
    <div className="app">
      <header className="app-header">
        <h1>Investment Account Calculator</h1>
        <p>Calculate your investment growth with and without monthly deposits</p>
      </header>

      <main className="app-main">
        <InputForm onCalculate={handleCalculate} />

        {results && (
          <div className="results-container">
            <ResultsTable
              title="Balance and Interest Without Additional Monthly Deposits"
              yearlyData={results.withoutDeposit}
            />
            <ResultsTable
              title={`Balance and Interest With Additional $${results.monthlyDeposit.toFixed(2)} Monthly Deposits`}
              yearlyData={results.withDeposit}
            />
          </div>
        )}
      </main>
    </div>
  );
}

export default App;
