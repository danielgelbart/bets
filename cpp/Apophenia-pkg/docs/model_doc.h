/** \file */ /**\defgroup models */

/** 
 The Multinomial Probit model.

  \deprecated  Use \ref apop_probit, which handles multiple options.
 \hideinitializer \ingroup models */
enum apop_multinomial_probit {
model_specific_x1x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Log likelihood</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Estimate_results_x1x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
};

/** 
 The Poisson distribution.

\f$p(k) = {\mu^k \over k!} \exp(-\mu), \f$

 \hideinitializer \ingroup models */
enum apop_poisson {
model_specific_x2x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x2x_, /**< <tt>Poisson distribution</tt>*/
Input_format_x2x_, /**<   Location of data in the grid is not relevant; send it a 1 x N, N x 1, or N x M and it will all be the same.*/
Parameter_format_x2x_, /**<   One parameter, the zeroth element of the vector.    */
Estimate_results_x2x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
 
Unless you decline it by adding the \ref apop_parts_wanted_settings group, I will also give you the variance of the parameter, via bootstrap, stored in a page named <tt>\<Covariance\></tt>.

</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>. </td></tr>
</table> */
RNG_x2x_, /**<  Just a wrapper for \c gsl_ran_poisson.  */
};

/** 
 A stack of models.

For the case when you need to bundle two uncorrelated models into one larger model. For example, the prior for a multivariate normal (whose parameters are a vector of means and a covariance matrix) is a Multivariate Normal-Wishart pair.

 \hideinitializer \ingroup models */
enum apop_stack {
model_specific_x3x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prob.</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Name_x3x_, /**< <tt>Only one model input; returning a copy of that model.</tt>*/
Input_format_x3x_, /**<      There are two means of handling the input format. If the settings group attached to the data set has a non-\c NULL \c splitpage element, then 
Append the second data set as an additional page to the first data set, and name the second set with the name you listed in \c splitpage; see the example.  

If \c splitpage is \c NULL, then I will send the same data set to both models.
*/
Parameter_format_x3x_, /**<   
currently \c NULL; check the sub-models for their parameters.
*/
Estimate_results_x3x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
Settings_x3x_, /**<    \ref apop_stack_settings
*/
};

/** 
 The \f$n\f$--option generalization of the \ref apop_binomial "Binomial distribution".

 \hideinitializer \ingroup models */
enum apop_multinomial {
model_specific_x4x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x4x_, /**< <tt>Binomial distribution</tt>*/
Input_format_x4x_, /**<  Each row of the matrix is one observation: a set of draws from a single bin.
  The number of draws of type zero are in column zero, the number of draws of type one in column one, et cetera.

\li You may have a set of several Bernoulli-type draws, which could be summed together to form a single Binomial draw.
See \ref apop_data_to_dummies to do the aggregation (using the <tt>.keep_first='y'</tt> option).
*/
Parameter_format_x4x_, /**< 
        The parameters are kept in the vector element of the \c apop_model parameters element. \c parameters->vector->data[0]==n;
        \c parameters->vector->data[1...]==p_1....

The numeraire is bin zero, meaning that \f$p_0\f$ is not explicitly listed, but is
\f$p_0=1-\sum_{i=1}^{k-1} p_i\f$, where \f$k\f$ is the number of bins. Conveniently enough,
the zeroth element of the parameters vector holds \f$n\f$, and so a full probability vector can
easily be produced by overwriting that first element. Continuing the above example: 
\code 
int n = apop_data_get(estimated->parameters, 0, -1); 
apop_data_set(estimated->parameters, 0, 1 - (apop_sum(estimated->parameters)-n)); 
\endcode
And now the parameter vector is a proper list of probabilities.

\li Because an observation is a single row, the number of bins, \f$k\f$ is set to equal
the length of the first row (counting both vector and matrix elements, as appropriate).
The covariance matrix will be \f$k \times k\f$.

\li Each row should sum to \f$N\f$, the number of draws. The estimation routine doesn't check this, but instead uses the average sum across all rows.
*/
Estimate_results_x4x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
  As per the parameter format. Has a <tt>\<Covariance\></tt> page with the covariance matrix for the \f$p\f$s (\f$n\f$ effectively has no variance).  
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>. </td></tr>
</table> */
RNG_x4x_, /**<  Returns a single vector of length \f$k\f$, the result of an imaginary tossing 
        of \f$N\f$ balls into \f$k\f$ urns, with the given probabilities.
            */
};

/** 


\f$ Y(x, b) 	= (b-1) \gamma(b) \gamma(k) / \gamma(k+b)			\f$

\f$ \ln Y(x, b)	= \ln(b-1) + ln\gamma(b) + \ln\gamma(k) - \ln\gamma(k+b)	\f$

\f$ d\ln Y/db	= 1/(b-1)  + \psi(b) - \psi(k+b)				\f$

apop_yule.estimate() is an MLE, so feed it appropriate \ref apop_mle_settings.

 \hideinitializer \ingroup models */
enum apop_yule {
model_specific_x5x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x5x_, /**< <tt>Yule distribution</tt>*/
Input_format_x5x_, /**<      
Ignores the matrix structure of the input data, so send in a 1 x N, an N x 1, or an N x M.

See also \ref apop_data_rank_compress for means of dealing with one more input data format.*/
Parameter_format_x5x_, /**<   One element at the top of the parameter set's vector.*/
Estimate_results_x5x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x5x_, /**<  Cribbed from <a href="http://cgm.cs.mcgill.ca/~luc/mbookindex.html>Devroye (1986)</a>, p 553.  */
};

/** 
 Ordinary least squares. Weighted least squares is also handled by this model.
You can also use it for a lot of not-entirely linear models based on the form \f$Y = f(x_1) + f(x_2) + ... + \epsilon\f$.

 \hideinitializer \ingroup models */
enum apop_ols {
model_specific_x6x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x6x_, /**< <tt>Ordinary Least Squares</tt>*/
Input_format_x6x_, /**<   See \ref dataprep.*/
Prep_routine_x6x_, /**<       Focuses on the data shunting. 
*/
Parameter_format_x6x_, /**<   A vector of OLS coefficients. coeff. zero
                         refers to the constant column, if any. */
Estimate_results_x6x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
 You can specify whether the data is modified with an \ref apop_lm_settings group. If so, see \ref dataprep for details. Else, left unchanged.

</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">

The \c parameters set will hold the coefficients; the first coefficient will be the
coefficient on the constant term, and the remaining will correspond to the independent
variables. It will therefore be of size <tt>(data->size2)</tt>.

I add a page named <tt>\<Covariance\></tt>, which gives the covariance matrix for the
estimated parameters (not the data itself).

</td></tr>
<tr><td style="vertical-align:top"><tt>parameter models</tt></td><td style="vertical-align:top">
  For the mean, a noncentral \f$t\f$ distribution (\ref apop_t_distribution).</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
 Reports log likelihood, and runs \ref apop_estimate_coefficient_of_determination 
to add \f$R^2\f$-type information (SSE, SSR, \&c) to the info page.

Residuals: I add a page named <tt>\<Predicted\></tt>, with three columns. If this is a model
with a single dependent and lots of independent vars, then the first column is the
actual data. Let our model be \f$ Y = \beta X + \epsilon\f$. Then the second column
is the predicted values: \f$\beta X\f$, and the third column is the residuals:
\f$\epsilon\f$. The third column is therefore always the first minus the second,
and this is probably how that column was calculated internally.

Given your estimate \c est, the zeroth element is one of <br> 
<tt> apop_data_get(est->info, .page= "Predicted", .row=0, .colname="observed"),</tt><br>
<tt> apop_data_get(est->info, .page= "Predicted", .row=0, .colname="predicted") or</tt><br>
<tt> apop_data_get(est->info, .page= "Predicted", .row=0, .colname="residual").</tt><br>
</td></tr>
</table> */
RNG_x6x_, /**<   Linear models are typically only partially defined probability models. For
OLS, we know that \f$P(Y|X\beta) \sim {\cal N}(X\beta, \sigma)\f$, because this is
an assumption about the error process, but we don't know much of anything about the
distribution of \f$X\f$.

The \ref apop_lm_settings group includes an \ref apop_model* element named \c
input_distribution. This is the distribution of the independent/predictor/X columns
of the data set.

The default is that <tt>input_distribution = apop_improper_uniform </tt>, meaning that
\f$P(X)=1\f$ for all \f$X\f$. So \f$P(Y, X) = P(Y|X)P(X) = P(Y|X)\f$. This seems to
be how many people use linear models: the \f$X\f$ values are taken as certain (as with
actually observed data) and the only question is the odds of the dependent variable. If
that's what you're looking for, just leave the default. This is sufficient for getting
log likelihoods under the typical assumption that the observed data has probability one.

<em>But</em> you can't draw from an improper uniform. So if you draw from a linear
model with a default <tt>input_distribution</tt>, then you'll get an error.

Alternatively, you may know something about the distribution of the input data. At
     the least, you could generate a PMF from the actual data:
     \code
    apop_settings_set(your_model, apop_lm, input_distribution, apop_estimate(inset, apop_pmf));
     \endcode
Now, random draws are taken from the input data, and the dependent variable value calculated via \f$X\beta+\epsilon\f$, where \f$X\f$ is the drawn value, \f$\beta\f$ the previously-estimated parameters and \f$\epsilon\f$ is a Normally-distributed random draw. Or change the PMF to any
other appropriate distribution, such as a \ref apop_multivariate_normal,
or an \ref apop_pmf filled in with more data, or perhaps something from
http://en.wikipedia.org/wiki/Errors-in-variables_models , as desired.  */
Examples_x6x_, /**< 
First, you will need a file named <tt>data</tt> in comma-separated form. The first column is the dependent variable; the remaining columns are the independent. For example:
\code
Y, X_1, X_2, X_3
2,3,4,5
1,2,9,3
4,7,9,0
2,4,8,16
1,4,2,9
9,8,7,6
\endcode

The program:
\include ols.c

If you saved this code to <tt>sample.c</tt>, then you can compile it with
\code
gcc sample.c -std=gnu99 -lapophenia -lgsl -lgslcblas -lsqlite3 -o run_me
\endcode

and then run it with <tt>./run_me</tt>. Alternatively, you may prefer to compile the program using a \ref makefile .

Feeling lazy? The program above was good form and demonstrated useful features, but the code below will do the same thing in two lines:

\code
#include <apop.h>
int main(){ apop_model_show(apop_estimate(apop_text_to_data("data"), apop_ols)); }
\endcode
*/
};

/** 
 A probability mass function is commonly known as a histogram, or still more commonly,
a bar chart. It indicates that at a given coordinate, there is a given mass.

Each row of the PMF's data set holds the coordinates, and the
<em>weights vector</em> holds the mass at the given point. This is in contrast to the
crosstab format, where the location is simply given by the position of the data point
in the grid.

For example, here is a typical crosstab:

<table>
<tr>            <td></td><td> col 0</td><td> col 1</td><td> col 2</td></tr>
<tr><td>row 0 </td><td>0</td><td> 8.1</td><td> 3.2</td></tr>
<tr><td>row 1 </td><td>0</td><td> 0</td><td> 2.2</td></tr>
<tr><td>row 2 </td><td>0</td><td> 7.3</td><td> 1.2</td></tr>
</table>

Here it is as a sparse listing:

<table>
<tr>        <td></td> value</td></td> dimension 1<td></td> dimension 2<td></tr>
<tr> <td>8.1</td> <td>0</td> <td>1</td> </tr>
<tr> <td>3.2</td> <td>0</td> <td>2</td> </tr>
<tr> <td>2.2</td> <td>1</td> <td>2</td> </tr>
<tr> <td>7.3</td> <td>2</td> <td>1</td> </tr>
<tr> <td>1.2</td> <td>2</td> <td>2</td> </tr>
</table>

The \c apop_pmf internally represents data in this manner, with the dimensions 
in the \c matrix, \c vector, and \c text element of the data set, and the cell values
are held in the \c weights element (<em>not the vector</em>).

If your data is in a crosstab (with entries in the matrix element for 2-D data or the
vector for 1-D data), then use \ref apop_crosstab_to_db to make the conversion. See also <a href="https://github.com/b-k/Apophenia/wiki/Crosstab-to-PMF">this page</a> for another crosstab-to-PMF function as well.

If your data is already in the sparse listing format (which is probably the case for 3-
or more dimensional data), then just point the model to your parameter set:

\code
apop_model *my_pmf = apop_model_copy(apop_pmf);
my_pmf->data = in_data;
//or equivalently:
apop_model *my_pmf = apop_estimate(in_data, apop_pmf);
\endcode

\li If the \c weights element is \c NULL, then I assume that all rows of the data set are
equally probable.
\li If the \c weights are present but sum to a not-finite value, the model's \c error element is set to \c 'w' when the estimation is run, and a warning printed.

 \hideinitializer \ingroup models */
enum apop_pmf {
model_specific_x7x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prob.</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Log likelihood</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x7x_, /**< <tt>PDF or sparse matrix</tt>*/
Input_format_x7x_, /**<      As above, you can input to the \c estimate
                      routine a 2-D matrix that will be converted into this form.     */
Parameter_format_x7x_, /**<   None. The list of observations and their weights are in the \c data set, not the \c parameters.*/
Estimate_results_x7x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
  The data you sent in is linked to (not copied).
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
  Still \c NULL.    
</td></tr>
</table> */
RNG_x7x_, /**<   Return the data in a random row of the PMF's data set. If there is a
      weights vector, i will use that to make draws; else all rows are equiprobable.

\li If you set \c draw_index to \c 'y', e.g., 

\code
Apop_settings_add(your_model, apop_pmf, draw_index, 'y');
\endcode

then I will return the row number of the draw, not the data in that row. 

\li  The first time you draw from a PMF with uneven weights, I will generate a
vector tallying the cumulative mass. Subsequent draws will have no computational
overhead. Because the  vector is built using the data on the first call to this or
the \c cdf method, do not rearrange or modify the data after the first call. I.e.,
if you choose to use \ref apop_data_sort or \ref apop_data_pmf_sort on your data,
do it before the first draw or CDF calculation.

\exception m->error='f' There is zero or NaN density in the CMF. I set the model's \c error element to \c 'f' and set <tt>out=NAN</tt>.
\exception m->error='a' Allocation error. I set the model's \c error element to \c 'a' and set <tt>out=NAN</tt>. Maybe try \ref apop_data_pmf_compress first?
*/
CDF_x7x_, /**<   <b>Assuming the data is sorted in a meaningful manner</b>, find the total mass up to a given data point.

That is, a CDF only makes sense if the data space is totally ordered. The sorting you
define using \ref apop_data_sort defines that ordering.

\li The input data should have the same number of columns as the data set used to construct the PMF. I use only the first row.

\li If the observation is not found in the data, return zero.

\li  The first time you get a CDF from from a data set with uneven weights, I
will generate a vector tallying the cumulative mass. Subsequent draws will have no
computational overhead. Because the  vector is built using the data on the first call
to this or the \c cdf method, do not rearrange or modify the data after the first
call. I.e., if you choose to use \ref apop_data_sort or \ref apop_data_pmf_sort on
your data, do it before the first draw or CDF calculation.
 */
Settings_x7x_, /**<    \ref apop_pmf_settings
*/
};

/** 
 Instrumental variable regression

Operates much like the \ref apop_ols model, but the input parameters also need to have
a table of substitutions (like the addition of the <tt>.instruments</tt> setting in
the example below). The vector element of the table lists the column numbers to be
substituted (the dependent var is zero; first independent col is one), and then one
column for each item to substitute.

\li If the vector of your apop_data set is \c NULL, then I will use the row names to find
the columns to substitute. This is generally more robust and/or convenient.

\li If the \c instruments data set is somehow \c NULL or empty, I'll just run OLS. 

\li Don't forget that the \ref apop_lm_settings group has a \c destroy_data setting. If
you set that to \c 'y', I will overwrite the column in place, saving the trouble of
copying the entire data set.

 \hideinitializer \ingroup models */
enum apop_iv {
model_specific_x8x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x8x_, /**< <tt>instrumental variables</tt>*/
Input_format_x8x_, /**<   See \ref apop_ols; see \ref dataprep. */
Prep_routine_x8x_, /**<   Focuses on the data shunting. */
Parameter_format_x8x_, /**<   As per \ref apop_ols */
Estimate_results_x8x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
Examples_x8x_, /**<  
\include  iv.c
*/
};

/** 
 A multivariate generalization of the \ref apop_beta "Beta distribution".

 \hideinitializer \ingroup models */
enum apop_dirichlet {
model_specific_x9x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x9x_, /**< <tt>Dirichlet distribution</tt>*/
Input_format_x9x_, /**<       Each row of your data matrix is a single observation.  */
Parameter_format_x9x_, /**<    The estimated parameters are in the output model's <tt>parameters->vector</tt>. The size of the model is determined by the width of your input data set, so later RNG draws, \&c will match in size.*/
Estimate_results_x9x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x9x_, /**<   A call to \c gsl_ran_dirichlet.*/
};

/** 
 The Logit model.

Apophenia makes no distinction between the bivariate logit and the multinomial logit. This does both.

  The likelihood of choosing item \f$j\f$ is:
  \f$e^{x\beta_j}/ (\sum_i{e^{x\beta_i}})\f$

  so the log likelihood is 
  \f$x\beta_j  - ln(\sum_i{e^{x\beta_i}})\f$

 \hideinitializer \ingroup models */
enum apop_logit {
model_specific_x10x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Score</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x10x_, /**< <tt>Logit</tt>*/
Input_format_x10x_, /**<   The first column of the data matrix this model expects is zeros,
ones, ..., enumerating the factors; to get there, try \ref apop_data_to_factors; if
you  forget to run it, I'll run it on the first data column for you.  The remaining
columns are values of the independent variables. Thus, the model will return [(data
columns)-1]\f$\times\f$[(option count)-1] parameters.  Column names are options;
row names are input variables.
*/
Prep_routine_x10x_, /**<  You will probably want to convert some column of your data into
factors, via \ref apop_data_to_factors. If you do, then that adds a page of factors
to your data set (and of course adjusts the data itself). If I find a factor page,
I will use that info; if not, then I will run \ref apop_data_to_factors on the first
column (the vector if there is one, else the first column of the matrix.)

Also, if there is no vector, then I will move the first column of the matrix, and
replace that matrix column with a constant column of ones, just like with OLS.
*/
Parameter_format_x10x_, /**<   As above.    */
Estimate_results_x10x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x10x_, /**<  Much like the \ref apop_ols RNG, qv. Returns the category drawn.

\li PS: Here is a nice trick used in the implementation. let \f$y_i = x\beta_i\f$.
  Then
\f[ln(\sum_i{e^{x\beta_i}}) = max(y_i) + ln(\sum_i{e^{y_i - max(y_i)}}).\f]

The elements of the sum are all now exp(something negative), so 
overflow won't happen, and if there's underflow, then that term
must not have been very important. [This trick is attributed to Tom
Minka, who implemented it in his Lightspeed Matlab toolkit.]

Here is an artifical example:

\include fake_logit.c
*/
};

/** 
 The Probit model.

  Apophenia makes no distinction between the bivariate probit and the multinomial probit. This one does both.

 \hideinitializer \ingroup models */
enum apop_probit {
model_specific_x11x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x11x_, /**< <tt>Probit</tt>*/
Input_format_x11x_, /**<   
The first column of the data matrix this model expects is zeros, ones, ..., enumerating
the factors; to get there, try \ref apop_data_to_factors; if you  forget to run it,
I'll run it on the first data column for you.  The remaining columns are values of the
independent variables. Thus, the model will return [(data columns)-1]\f$\times\f$[(option
count)-1] parameters.  Column names are options; row names are input variables.
*/
Prep_routine_x11x_, /**<  You will probably want to convert some column of your data into
factors, via \ref apop_data_to_factors. If you do, then that adds a page of factors
to your data set (and of course adjusts the data itself). If I find a factor page,
I will use that info; if not, then I will run \ref apop_data_to_factors on the first
column (the vector if there is one, else the first column of the matrix.)

Also, if there is no vector, then I will move the first column of the matrix, and
replace that matrix column with a constant column of ones, just like with OLS.
*/
Parameter_format_x11x_, /**<   As above */
Estimate_results_x11x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x11x_, /**<   See \ref apop_ols; this one is similar but produces a category number instead of OLS's continuous draw.
*/
};

/** 
 The Gamma distribution

\f$G(x, a, b)     = {1\over (\Gamma(a) b^a)}  x^{a-1} e^{-x/b}\f$

\f$ln G(x, a, b)= -ln \Gamma(a) - a ln b + (a-1)ln(x) + -x/b\f$

\f$d ln G/ da    =  -\psi(a) - ln b + ln(x) \f$    (also, \f$d ln \gamma = \psi\f$)

\f$d ln G/ db    =  -a/b + x/(b^2) \f$

 \hideinitializer \ingroup models */
enum apop_gamma {
model_specific_x12x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x12x_, /**< <tt>Gamma distribution</tt>*/
Input_format_x12x_, /**<      
Location of data in the grid is not relevant; send it a 1 x N, N x 1, or N x M and it will all be the same.     

\li See also \ref apop_data_rank_compress for means of dealing with one more input data format.*/
Parameter_format_x12x_, /**<    First two elements of the vector.   */
Estimate_results_x12x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x12x_, /**<  Just a wrapper for \c gsl_ran_gamma.

See the notes for \ref apop_exponential on a popular alternate form.  */
};

/** 
 The Wishart distribution, which is currently somewhat untested. 

Here's the likelihood function. \f$p\f$ is the dimension of the data and covariance
matrix, \f$n\f$ is the degrees of freedom, \f$\mathbf{V}\f$ is the \f$p\times p\f$
matrix of Wishart parameters, and \f${\mathbf{W}}\f$ is the \f$p\times p\f$ matrix whose
likelihood is being evaluated.  \f$\Gamma_p(\cdot)\f$ is the \ref apop_multivariate_gamma
"multivariate gamma function".

\f[
P(\mathbf{W}, \mathbf{V}) = \frac{\left|\mathbf{W}\right|^\frac{n-p-1}{2}}
                         {2^\frac{np}{2}\left|{\mathbf V}\right|^\frac{n}{2}\Gamma_p(\frac{n}{2})} \exp\left(-\frac{1}{2}{\rm Tr}({\mathbf V}^{-1}\mathbf{W})\right)\f]

See also notes in \ref tfchi.

 \hideinitializer \ingroup models */
enum apop_wishart {
model_specific_x13x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x13x_, /**< <tt>Wishart distribution</tt>*/
Input_format_x13x_, /**<      Each row of the input matrix is a single square matrix,
                      flattened; use \ref apop_data_pack to convert your
                      sequence of matrices into rows.     */
Prep_routine_x13x_, /**<    Just allocates the parameters based on the size of the input data.       */
Parameter_format_x13x_, /**<   \f$N\f$ (the degrees of freedom) is the zeroth element of the vector. The matrix holds the matrix of parameters.*/
Estimate_results_x13x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x13x_, /**<   You can use this to generate random covariance matrices, should you need them. See example below. */
Examples_x13x_, /**<  Making some random draws:

\code
apop_model *m = apop_estimate(yr_data, apop_wishart);
gsl_matrix *rmatrix = gsl_matrix_alloc(10, 10);
gsl_rng *r = apop_rng_alloc(8765);
for (int i=0; i< 1e8; i++){
    apop_draw(rmatrix->data, r, m);
    do_math_with_matrix(rmatrix);
}
\endcode */
};

/** 
 The kernel density smoothing of a PMF or histogram.

At each point along the histogram, put a distribution (default: Normal(0,1)) on top
of the point. Sum all of these distributions to form the output distribution.

Elements of \ref apop_kernel_density_settings that you may want to set:

\li \c data a data set, which, if  not \c NULL and \c !base_pmf , will be converted to an \ref apop_pmf model.
\li \c base_pmf This is the preferred format for input data. It is the histogram to be smoothed.
\li \c kernelbase The kernel to use for smoothing, with all parameters set and a \c p method. Popular favorites are \ref apop_normal and \ref apop_uniform.
\li \c set_params A function that takes in a single number and the model, and sets
the parameters accordingly. The function will call this for every point in the data
set. Here is the default, which is used if this is \c NULL. It simply sets the first
element of the model's parameter vector to the input number; this is appropriate for a
Normal distribution, where we want to center the distribution on each data point in turn.

\code
static void apop_set_first_param(apop_data *in, apop_model *m){
    m->parameters->vector->data[0]  = apop_data_get(in);
}
\endcode

For a Uniform[0,1] recentered around the first element of the PMF matrix, you could put this function in your code:

\code
void set_midpoint(apop_data * in, apop_model *m){
    apop_data_set(m->parameters, 0, -1, apop_data_get(in)+0.5);
    apop_data_set(m->parameters, 1, -1, apop_data_get(in)-0.5);
}
\endcode

 \hideinitializer \ingroup models */
enum apop_kernel_density {
model_specific_x14x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prob.</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Log likelihood</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Name_x14x_, /**< <tt>kernel density estimate</tt>*/
Input_format_x14x_, /**<   I'll estimate a \ref apop_pmf internally, so I
                   follow that format, which is one observation (of any format) per line.*/
Parameter_format_x14x_, /**<   None*/
Estimate_results_x14x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x14x_, /**<   Randomly selects a data point, then randomly draws from that sub-distribution.
 Returns 0 on success, 1 if unable to pick a sub-distribution (meaning the weights over the distributions are somehow broken), and 2 if unable to draw from the sub-distribution.
 */
CDF_x14x_, /**<  Sums the CDF to the given point of all the sub-distributions.*/
Settings_x14x_, /**<   \ref apop_kernel_density_settings*/
Examples_x14x_, /**< 
This example sets up and uses KDEs based on a Normal and a Uniform distribution.

\include kernel.c
*/
};

/** 
 The Beta distribution.

The beta distribution has two parameters and is restricted between zero and one. You
may also find \ref apop_beta_from_mean_var to be useful.

 \hideinitializer \ingroup models */
enum apop_beta {
model_specific_x15x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x15x_, /**< <tt>Beta distribution</tt>*/
Input_format_x15x_, /**<   Any arrangement of scalar values. */
Parameter_format_x15x_, /**<    a vector, v[0]=\f$\alpha\f$; v[1]=\f$\beta\f$    */
Estimate_results_x15x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>. </td></tr>
</table> */
RNG_x15x_, /**<   Produces a scalar \f$\in[0,1]\f$. */
};

/** 
  This is the two-parameter version of the Uniform,
expressing a uniform distribution over [a, b].

The MLE of this distribution is simply a = min(your data); b = max(your data).
Primarily useful for the RNG, such as when you have a Uniform prior model.

 \hideinitializer \ingroup models */
enum apop_uniform {
model_specific_x16x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prob.</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Name_x16x_, /**< <tt>Uniform distribution</tt>*/
Input_format_x16x_, /**<   An unordered set of numbers in the data set's vector, matrix, or both.*/
Parameter_format_x16x_, /**<   Zeroth vector element is \f$a\f$, the min;
                          element one is \f$b\f$, the max. */
Estimate_results_x16x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>. </td></tr>
</table> */
};

/** 
 The Normal (Gaussian) distribution

You know it, it's your attractor in the limit, it's the Gaussian distribution.

\f$N(\mu,\sigma^2) = {1 \over \sqrt{2 \pi \sigma^2}} \exp (-x^2 / 2\sigma^2)\f$

\f$\ln N(\mu,\sigma^2) = (-(x-\mu)^2 / 2\sigma^2) - \ln (2 \pi \sigma^2)/2 \f$

\f$d\ln N(\mu,\sigma^2)/d\mu = (x-\mu) / \sigma^2 \f$

\f$d\ln N(\mu,\sigma^2)/d\sigma^2 = ((x-\mu)^2 / 2(\sigma^2)^2) - 1/2\sigma^2 \f$

See also the \ref apop_multivariate_normal.

 \hideinitializer \ingroup models */
enum apop_normal {
model_specific_x17x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x17x_, /**< <tt>Normal distribution</tt>*/
Input_format_x17x_, /**<      I use the elements of the matrix and vector, without regard to their order or position. */
Parameter_format_x17x_, /**<   
  As is custom, parameter zero (in the vector) is the mean, parmeter one is the standard deviation (i.e., the square root of the variance). 
*/
Estimate_results_x17x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
 Zeroth vector element is \f$\mu\f$, element 1 is \f$\sigma\f$.
 A page is added named <tt>\<Covariance\></tt> with the 2 \f$\times\f$ 2 covariance matrix for these two parameters
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
  Reports the log likelihood.</td></tr>
</table> */
Predict_x17x_, /**<   Returns the expected value. The <tt>->more</tt>
                 element holds a \ref apop_data set with the title <tt>\<Covariance\></tt>, whose 
                 matrix holds the covariance of the mean.
*/
RNG_x17x_, /**<  An apophenia wrapper for the GSL's Normal RNG.

This one asks explicitly for a mean, and the GSL assumes zero and lets you add the mean yourself.  */
Settings_x17x_, /**<    None.*/
};

/** 
 The Exponential distribution.

\f$Z(\mu,k) 	= \sum_k 1/\mu e^{-k/\mu} 			\f$ <br>
\f$ln Z(\mu,k) 	= \sum_k -\ln(\mu) - k/\mu			\f$ <br>
\f$dln Z(\mu,k)/d\mu 	= \sum_k -1/\mu + k/(\mu^2)			\f$ <br>

Some write the function as:
\f$Z(C,k) dx = \ln C C^{-k}. \f$
If you prefer this form, just convert your parameter via \f$\mu = {1\over \ln C}\f$
(and convert back from the parameters this function gives you via \f$C=\exp(1/\mu)\f$).

 \hideinitializer \ingroup models */
enum apop_exponential {
model_specific_x18x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x18x_, /**< <tt>Exponential distribution</tt>*/
Input_format_x18x_, /**<   
Ignores the matrix structure of the input data, so send in a 1 x N, an N x 1, or an N x M.
\li See also \ref apop_data_rank_compress for means of dealing with one more input data format.
                    */
Parameter_format_x18x_, /**<    \f$\mu\f$ is in the zeroth element of the vector.   */
Estimate_results_x18x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>. </td></tr>
</table> */
RNG_x18x_, /**<  Just a wrapper for \c gsl_ran_exponential.  */
CDF_x18x_, /**<   Produces a single number.*/
};

/** 
 The mixture model transformation: a linear combination of multiple models.  

Generated via \ref apop_model_mixture.

Note that a kernel density is a mixture of a large number of homogeneous models, where each is typically centered around a point in your data. For such situations, \ref apop_kernel_density will be easier to use.

Use \ref apop_model_mixture to produce one of these models. In the examples below, some are generated from unparameterized input models with a form like 

\code
apop_model *mf = apop_model_mixture(apop_model_copy(apop_normal), apop_model_copy(apop_normal));
Apop_model_add_group(mf, apop_mle, .starting_pt=(double[]){50, 5, 80, 5},
                                   .step_size=3, .tolerance=1e-6);
apop_model_show(apop_estimate(dd, mf));
\endcode

One can also skip the estimation and use already-parameterized models as input to \ref apop_model_mixture, e.g.:

\code
apop_model *r_ed = apop_model_mixture(apop_model_set_parameters(apop_normal, 54.6, 5.87),
                       apop_model_set_parameters(apop_normal, 80.1, 5.87));
apop_data *wts = apop_data_falloc((2), 0.36, 0.64);
Apop_settings_add(r_ed, apop_mixture, weights, wts->vector);
printf("LL=%g\n", apop_log_likelihood(dd, r_ed));
\endcode

Notice that the weights vector has to be added after the model is set up. If none is given, then equal weights are assigned to all components of the mixture.


One can think of the estimation as a missing-data problem: each data point originated
in one distribution or the other, and if we knew with certainty which data point
came from which distribution, then the estimation problem would be trivial:
just generate the subsets and call <tt>apop_estimate(dataset1, model1)</tt>, ...,
<tt>apop_estimate(datasetn, modeln)</tt> separately.  But the assignment of which
element goes where is unknown information, which we guess at using an E-M algorithm. The
standard algorithm starts with an initial set of parameters for the models, and assigns
each data point to its most likely model. It then re-estimates the
model parameters using their subsets. The standard algorithm, see e.g. <a
href="http://www.jstatsoft.org/v32/i06/paper">this PDF</a>, repeats until it arrives
at an optimum.

Thus, the log likelihood method for this model includes a step that allocates each data
point to its most likely model, and calculates the log likelihood of each observation
using its most likely model. [It would be a valuable extension to extend this to
not-conditionally IID models. Commit \c 1ac0dd44 in the repository had some notes on
this, now removed.]  As a side-effect, it calculates the odds of drawing from each model
(the vector λ). Following the above-linked paper, the probability for a given
observation under the mixture model is its probability under the most likely model
weighted by the previously calculated λ for the given model.

Apohenia modifies this routine slightly because it uses the same maximum likelihood
back-end that most other <tt>apop_model</tt>s use for estimation. The ML search algorithm
provides model parameters, then the LL method allocates observations and reports a LL to
the search algorithm, then the search algorithm uses its usual rules to step to the next
candidate set of parameters. This provides slightly more flexibility in the search.

\li <b>Estimations of mixture distributions can be sensitive to initial conditions.</b>
You are encouraged to try a sequence random starting points for your model parameters.
Some authors recommend plotting the data and eyeballing a guess as to the model parameters.

Determining to which parts of a mixture to assign a data point is a
well-known hard problem, which is often not solvable--that information is basically lost. 

 \hideinitializer \ingroup models */
enum apop_mixture {
model_specific_x19x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x19x_, /**< <tt>Mixture of models</tt>*/
Input_format_x19x_, /**<    The same data gets sent to each of the component models of the
mixture. Each row is an observation, and the estimation routine assumes that models are
conditionally IID (i.e., having chosen what component of the mixture the observation
comes from, its likelihood can be calculated independently of all other observations).
*/
Parameter_format_x19x_, /**<  The parameters are broken out in a readable form in the
    settings group, so your best bet is to use those. See the sample code for usage.<br>
    The <tt>parameter</tt> element is a single vector piling up all elements, beginning
    with the first $n-1$ weights, followed by an <tt>apop_data_pack</tt> of each model's
    parameters in sequence. Because all elements are in a single vector, one could run a
    maximum likelihood search for all components (including the weights) at once. Fortunately
    for parsing, the <tt>log_likehood</tt>, <tt>estimate</tt>, and other methods unpack
    this vector into its component parts for you.
*/
Estimate_results_x19x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x19x_, /**<  Uses the weights to select a component model, then makes a draw from that component.
The model's \c dsize (draw size) element is set when you set up the model in the
model's \c prep method (automatically called by \ref apop_estimate, or call it directly)
iff all component models have the same \c dsize.
*/
Settings_x19x_, /**<    \ref apop_mixture_settings 
*/
Examples_x19x_, /**< 
The first example uses a text file \c faith.data, in the \c tests directory of the distribution.
\include faithful.c

\include hills2.c
*/
};

/** 
 Apply a coordinate transformation of the data to
produce a distribution over the transformed data space. This is sometimes called a Jacobian transformation.

\li This is still in beta. Expect the interface to change.

Here is an example that replicates the Lognormal distribution.

\include jacobian.c

 \hideinitializer \ingroup models */
enum apop_coordinate_transform {
model_specific_x20x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x20x_, /**< <tt>Jacobian-transformed model</tt>*/
Input_format_x20x_, /**<  The input data is sent to the first model, so use the input format for that model.*/
Estimate_results_x20x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
Settings_x20x_, /**<    \ref apop_ct_settings

*/
};

/** 

Wikipedia has notes on the <a href="http://en.wikipedia.org/wiki/Zipf_distribution">Zipf distribution</a>. 
\f$Z(a)   = {1\over \zeta(a) * i^a}        \f$

\f$lnZ(a) = -(\log(\zeta(a)) + a \log(i))    \f$

apop_zipf.estimate() is an MLE, so feed it appropriate \ref apop_mle_settings.

 \hideinitializer \ingroup models */
enum apop_zipf {
model_specific_x21x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Name_x21x_, /**< <tt>Zipf distribution</tt>*/
Input_format_x21x_, /**<     Ignores the matrix structure of the input data, so send in a 1 x N, an N x 1, or an N x M.

See also \ref apop_data_rank_compress for means of dealing with one more input data format.
*/
Parameter_format_x21x_, /**<  One item in the parameter set's vector.    */
Estimate_results_x21x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x21x_, /**<  Returns a ranking: If the population were Zipf distributed, you're most
likely to get the 1st most common item, so this produces a lot of ones,
a great deal of twos, and so on.

Cribbed from <a href="http://cgm.cs.mcgill.ca/~luc/mbookindex.html>Devroye (1986)</a>, Chapter 10, p 551.  */
};

/** 
 The improper uniform returns \f$P(x) = 1\f$ for every value of x, all the
time (and thus, log likelihood(x)=0).  It has zero parameters. It is
useful, for example, as an input to Bayesian updating, to represent a
fully neutral prior.

\li See also the \ref apop_uniform model.

 \hideinitializer \ingroup models */
enum apop_improper_uniform {
model_specific_x22x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prob.</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Name_x22x_, /**< <tt>Improper uniform distribution</tt>*/
Input_format_x22x_, /**<       Ignored.*/
Parameter_format_x22x_, /**<   \c NULL */
Estimate_results_x22x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
   \c NULL
</td></tr>
</table> */
RNG_x22x_, /**<  The \c draw function makes no sense, and therefore sets the value in <tt>*out</tt> to \c NAN, returns 1, and prints a warning if <tt>apop_opts.verbose >=1</tt>.*/
CDF_x22x_, /**<  Half of the distribution is less than every given point, so the CDF always
             returns 0.5. One could perhaps make an argument that this should really be
             infinity, but a half is more in the spirit of the distribution's
             use to represent a lack of information. */
};

/** 
 A model that constrains the base model to within some
data constraint. E.g., truncate \f$P(d)\f$ to zero for all \f$d\f$ outside of a given
constraint. Generate using \ref apop_model_dconstrain .

\li This is still in beta. Expect the interface to change.

The log likelihood works by using the \c base_model log likelihood, and then scaling
it based on the part of the base model's density that is within the constraint. If you
have an easy means of specifying what that density is, please do, as in the example. If
you do not, the log likelihood will calculate it by making \c draw_ct random draws from
the base model and checking whether they are in or out of the constraint. Because this
default method is stochastic, there is some loss of precision, and conjugate gradient
methods may get confused.

Here is an example that makes a few draws and estimations from data-constrained models.

 \hideinitializer \ingroup models */
enum apop_dconstrain {
model_specific_x23x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Prob.</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x23x_, /**< <tt>%s, with some params fixed</tt>*/
Input_format_x23x_, /**<  That of the base model.*/
Parameter_format_x23x_, /**<  That of the base model. In fact, the \c parameters element is a pointer to the base model \c parameters, so both are modified simultaneously.*/
Estimate_results_x23x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x23x_, /**<  Draw from the base model; if the draw is outside the constraint, throw it out and try again. */
Settings_x23x_, /**<    \ref apop_dconstrain_settings
*/
Examples_x23x_, /**< 
\include dconstrain.c
*/
};

/** 
 The Weighed Least Squares model
This is a (deprecated) synonym for \ref apop_ols, qv.  If you use the \ref apop_ols
model and provide weights in \c your_input_data->weights, then I will use them
appropriately. That is, the \ref apop_ols model really implements Weighted Least Squares,
but in most cases <tt>weights==NULL</tt> and the math reduces to the special case of
Ordinary Least Squares.

 \hideinitializer \ingroup models */
enum apop_wls {
model_specific_x24x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Log likelihood</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Estimate_results_x24x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
};

/** 
 The Lognormal distribution

The log likelihood function for the lognormal distribution:

\f$f = exp(-(ln(x)-\mu)^2/(2\sigma^2))/ (x\sigma\sqrt{2\pi})\f$
\f$ln f = -(ln(x)-\mu)^2/(2\sigma^2) - ln(x) - ln(\sigma\sqrt{2\pi})\f$

 \hideinitializer \ingroup models */
enum apop_lognormal {
model_specific_x25x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x25x_, /**< <tt>Lognormal distribution</tt>*/
Input_format_x25x_, /**<      I use the all elements of the matrix and vector, without regard to their order. */
Parameter_format_x25x_, /**<   Zeroth vector element is the mean (after logging); first is the std dev (after logging)    */
Estimate_results_x25x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>. </td></tr>
</table> */
RNG_x25x_, /**<  An Apophenia wrapper for the GSL's Normal RNG, exp'ed.  */
};

/** 
 The t distribution, primarily for descriptive purposes.

If you want to test a hypothesis, you probably don't need this, and should instead use \ref apop_test.  See notes in \ref tfchi.  

 \hideinitializer \ingroup models */
enum apop_t_distribution {
model_specific_x26x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Name_x26x_, /**< <tt>t distribution</tt>*/
Input_format_x26x_, /**<      Unordered list of scalars in the matrix and/or vector.     */
Parameter_format_x26x_, /**<   vector->data[0] = mu<br>
                            vector->data[1] = sigma<br>
                            vector->data[2] = df */
Estimate_results_x26x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
};

/** 
 The Bernoulli model: A single random draw with probability \f$p\f$.

 \hideinitializer \ingroup models */
enum apop_bernoulli {
model_specific_x27x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">CDF</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x27x_, /**< <tt>Bernoulli distribution</tt>*/
Input_format_x27x_, /**< 
  The matrix or vector can have any size, and I just count up zeros
  and non-zeros. The Bernoulli parameter \f$p\f$ is the percentage of non-zero
  values in the matrix. Its variance is \f$p(1-p)\f$.
*/
Parameter_format_x27x_, /**<  A vector of length one */
Estimate_results_x27x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
 \f$p\f$ is the only element in the vector. A
<tt>\<Covariance\></tt> page has the variance of \f$p\f$ in the (0,0)th element of the matrix.
</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>.
</td></tr>
</table> */
RNG_x27x_, /**<  Returns a single zero or one. */
Settings_x27x_, /**<  None. */
};

/** 
 Use random draws or parameter estimates output from a first model as input data for a second model.

\li This is still in beta. Expect the interface to change.

 \hideinitializer \ingroup models */
enum apop_dcomposition {
model_specific_x28x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x28x_, /**< <tt>Data-composed model</tt>*/
Input_format_x28x_, /**<  The input data is sent to the first model, so use the input format for that model.*/
Estimate_results_x28x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
Settings_x28x_, /**<    \ref apop_composition_settings
*/
};

/** 
 This is the multivariate generalization of the Normal distribution.

 \hideinitializer \ingroup models */
enum apop_multivariate_normal {
model_specific_x29x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="altcolor">RNG</td>
<td class="altcolor">M</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x29x_, /**< <tt>Multivariate normal distribution</tt>*/
Input_format_x29x_, /**<      Each row of the matrix is an observation.*/
Parameter_format_x29x_, /**<   An \c apop_data set whose vector element is the vector of
                            means, and whose matrix is the covariances.

If you had only one dimension, the mean would be a vector of size one, and the covariance matrix a \f$1\times 1\f$ matrix. This differs from the setup for \ref apop_normal, which outputs a single vector with \f$\mu\f$ in element zero and \f$\sigma\f$ in element one.*/
Estimate_results_x29x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
  Format as above. The <tt>\<Covariance\></tt> page gives
the covariance matrix of the means.

</td></tr>
<tr><td style="vertical-align:top"><tt>info</tt></td><td style="vertical-align:top">
   Reports <tt>log likelihood</tt>.   </td></tr>
</table> */
RNG_x29x_, /**<   The RNG fills an input array whose length is based on the input parameters.

 The nice, easy method from Devroye, p 565 */
Settings_x29x_, /**<    None.    */
};

/** 
 The multi-draw generalization of the Bernoulli; the two-bin special case of the \ref apop_multinomial "Multinomial distribution".
This differs from the \ref apop_multinomial only in the input data format.

It is implemented as an alias of the \ref apop_multinomial model, except that it has
a CDF, <tt>.vsize==2</tt> and <tt>.dsize==1</tt> (i.e., we know it has two parameters
and a draw returns a scalar).

 \hideinitializer \ingroup models */
enum apop_binomial {
model_specific_x30x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="memitem">Estimation</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Log likelihood</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Prep routine</td>
<td class="memitem">D</td>
</tr>
</table> </td></tr></table>*/
Input_format_x30x_, /**<  Each row of the matrix is one observation, consisting of two elements.
  The number of draws of type zero (sometimes read as `misses' or `failures') are in column zero, 
  the number of draws of type one (`hits', `successes') in column one.
*/
Parameter_format_x30x_, /**<    a vector, v[0]=\f$n\f$; v[1]=\f$p_1\f$. Thus, \f$p_0\f$
        isn't written down; see \ref apop_multinomial for further discussion.
        If you input $v[1]>1$ and <tt>apop_opts.verbose >=1</tt>, the log likelihood
        function will throw a warning.
*/
Estimate_results_x30x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
See parameter format.
</td></tr>
</table> */
RNG_x30x_, /**<  The RNG returns a single number representing the success count, not a
    vector of length two giving both the failure bin and success bin. This is notable
    because it differs from the input data format, but it tends to be what people expect
    from a Binomial RNG. For draws with both dimensions, use a \ref apop_multinomial model
    with <tt>.vsize =2</tt>.
*/
};

/** 
 Regression via loess smoothing

This uses a somewhat black-box routine, first written by Chamberlain, Devlin, Grosse,
and Shyu in 1988, to fit a smoothed series of quadratic curves to the input data,
thus producing a curve more closely fitting than a simple regression would.

The curve is basically impossible to describe using a short list of parameters, so the
representation is in the form of the \c predicted vector of the \c expected data set;
see below.

From the 1992 manual for the package:
``The method we will use to fit local regression models is called {\em loess}, which
is short for local regression, and was chosen as the name since a loess is a deposit
of fine clay or silt along a river valley, and thus is a surface of sorts. The word
comes from the German löss, and is pronounced löíss.''

 \hideinitializer \ingroup models */
enum apop_loess {
model_specific_x31x_, /**< <table cellpadding=3px><tr><td><table class="memproto">
<tr><td class="altcolor">Estimation</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">Prob.</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Log likelihood</td>
<td class="altcolor">M</td>
</tr>
<tr><td class="memitem">RNG</td>
<td class="memitem">D</td>
</tr>
</table></td><td><table class="memproto">
<tr><td class="memitem">Predict</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">CDF</td>
<td class="memitem">D</td>
</tr>
<tr><td class="memitem">Score</td>
<td class="memitem">D</td>
</tr>
<tr><td class="altcolor">Prep routine</td>
<td class="altcolor">M</td>
</tr>
</table> </td></tr></table>*/
Name_x31x_, /**< <tt>Loess smoothing</tt>*/
Input_format_x31x_, /**<   
The data is basically OLS-like:                     
the first column of the data is the dependent variable to be explained; subsequent
variables are the independent explanatory variables.  Thus, your input data can either
have a dependent vector plus explanatory matrix, or a matrix where the first column
is the dependent variable.

Unlike with OLS, I won't move your original data, and I won't add a <b>1</b>, because
that's not really the loess custom. You can of course set up your data that way if
you like.

If your data set has a weights vector, I'll use it.

In any case, all data is copied into the model's \ref apop_loess_settings. The code
is primarily FORTRAN code from 1988 converted to C; the data thus has to be converted
into a relatively obsolete internal format.

*/
Parameter_format_x31x_, /**<   The parameter vector is unused. */
Estimate_results_x31x_, /**< <table>
<tr><td style="vertical-align:top"><tt>data</tt></td><td style="vertical-align:top">
Unchanged.
</td></tr>
<tr><td style="vertical-align:top"><tt>parameters</tt></td><td style="vertical-align:top">
 None.  
</td></tr>
<tr><td style="vertical-align:top">settings</td><td style="vertical-align:top">

The \ref apop_loess_settings is filled with results (and internal processing cruft). The
\c out_model->info data set has a table giving the actual, \c predicted, and \c residual
columns, which is probably what you were looking for.  Try:
        \code
        apop_data_show(apop_data_get_page(output_model->info, "<Predicted>"));
        \endcode
        </td></tr>
</table> */
Predict_x31x_, /**<  
Fills in the zeroth column (ignoring and overwriting any data there), and at the data's <tt>->more</tt> pointer, adds an \ref
apop_data set named "Confidence" (i.e., 
\code
!strcmp(outdata->more->names->title, "Confidence") == 1.
\endcode 

This routine is in beta testing.
*/
};
