import './ResultsTable.css';

export default function ResultsTable({ title, yearlyData }) {
  const formatCurrency = (value) => {
    return new Intl.NumberFormat('en-US', {
      style: 'currency',
      currency: 'USD',
      minimumFractionDigits: 2,
      maximumFractionDigits: 2
    }).format(value);
  };

  return (
    <div className="results-table-container">
      <h3>{title}</h3>
      <table className="results-table">
        <thead>
          <tr>
            <th>Year</th>
            <th>Year End Balance</th>
            <th>Year End Earned Interest</th>
          </tr>
        </thead>
        <tbody>
          {yearlyData.map((data) => (
            <tr key={data.year}>
              <td>{data.year}</td>
              <td>{formatCurrency(data.balance)}</td>
              <td>{formatCurrency(data.interest)}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
