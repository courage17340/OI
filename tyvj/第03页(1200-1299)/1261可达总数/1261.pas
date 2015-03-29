var
 a,b,x,y,n,ans,i,j:longint;
begin
 readln(a,b,x,y,n);
 ans:=0;
 for i:=1 to a do
  for j:=1 to b do
   if abs(i-x)+abs(j-y)<=n then inc(ans);
 writeln(ans);
end.