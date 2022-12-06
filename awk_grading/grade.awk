BEGIN{
	i = 1;
	max = -99999;
}
{
	totalsum = ( $3+$4+$5 );
	marks[i] = totalsum;
	name[i] = $2;
	i= i+1;
	max= (max > totalsum) ? max : totalsum;

}
END{
	for (i=1; i<=10; i++){
		if(marks[i] == max){
			print(name[i]" "marks[i]" "100);}
		else{
			print(name[i]" "marks[i]" "(marks[i]*100)/max );}
        }
}
