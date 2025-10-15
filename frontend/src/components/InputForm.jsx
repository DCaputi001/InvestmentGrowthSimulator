import { useState } from 'react';
import './InputForm.css';

export default function InputForm({ onCalculate }) {
  const [initialInvestment, setInitialInvestment] = useState('');
  const [monthlyDeposit, setMonthlyDeposit] = useState('');
  const [annualInterest, setAnnualInterest] = useState('');
  const [years, setYears] = useState('');
  const [errors, setErrors] = useState({});

  const validateInputs = () => {
    const newErrors = {};

    if (!initialInvestment || parseFloat(initialInvestment) < 0) {
      newErrors.initialInvestment = 'Please enter a positive number';
    }
    if (!monthlyDeposit || parseFloat(monthlyDeposit) < 0) {
      newErrors.monthlyDeposit = 'Please enter a positive number';
    }
    if (!annualInterest || parseFloat(annualInterest) < 0) {
      newErrors.annualInterest = 'Please enter a positive number';
    }
    if (!years || parseInt(years) < 1) {
      newErrors.years = 'Please enter a positive number';
    }

    setErrors(newErrors);
    return Object.keys(newErrors).length === 0;
  };

  const handleSubmit = (e) => {
    e.preventDefault();

    if (validateInputs()) {
      onCalculate({
        initialInvestment: parseFloat(initialInvestment),
        monthlyDeposit: parseFloat(monthlyDeposit),
        annualInterest: parseFloat(annualInterest),
        years: parseInt(years)
      });
    }
  };

  return (
    <form className="input-form" onSubmit={handleSubmit}>
      <h2>Investment Calculator</h2>

      <div className="form-group">
        <label htmlFor="initialInvestment">Initial Investment Amount:</label>
        <input
          type="number"
          id="initialInvestment"
          step="0.01"
          value={initialInvestment}
          onChange={(e) => setInitialInvestment(e.target.value)}
          placeholder="Enter initial investment"
        />
        {errors.initialInvestment && <span className="error">{errors.initialInvestment}</span>}
      </div>

      <div className="form-group">
        <label htmlFor="monthlyDeposit">Monthly Deposit:</label>
        <input
          type="number"
          id="monthlyDeposit"
          step="0.01"
          value={monthlyDeposit}
          onChange={(e) => setMonthlyDeposit(e.target.value)}
          placeholder="Enter monthly deposit"
        />
        {errors.monthlyDeposit && <span className="error">{errors.monthlyDeposit}</span>}
      </div>

      <div className="form-group">
        <label htmlFor="annualInterest">Annual Interest (%):</label>
        <input
          type="number"
          id="annualInterest"
          step="0.01"
          value={annualInterest}
          onChange={(e) => setAnnualInterest(e.target.value)}
          placeholder="Enter annual interest rate"
        />
        {errors.annualInterest && <span className="error">{errors.annualInterest}</span>}
      </div>

      <div className="form-group">
        <label htmlFor="years">Number of Years:</label>
        <input
          type="number"
          id="years"
          value={years}
          onChange={(e) => setYears(e.target.value)}
          placeholder="Enter number of years"
        />
        {errors.years && <span className="error">{errors.years}</span>}
      </div>

      <button type="submit" className="calculate-btn">Calculate</button>
    </form>
  );
}
