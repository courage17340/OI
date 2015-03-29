var
 a,t:array[0..100000] of longint;
 z1,z2:array[0..100000] of longint;
 n,m1,m2,i,j,x,k,max:longint;
begin
 read(n);
 read(m1,m2);max:=0;
 for i:=1 to n do read(a[i]);
 fillchar(z1,sizeof(z1),0);
 fillchar(t,sizeof(t),0);
 for i:=2 to trunc(sqrt(m1)) do
  if m1 mod i=0 then
   while m1 mod i=0 do
    begin
     m1:=m1 div i;
     z1[i]:=z1[i]+m2;
     if max<i then max:=i;
    end;
 if m1>1 then begin z1[m1]:=z1[m1]+m2;if max<m1 then max:=m1;end;
 for i:=1 to n do
  begin
   fillchar(z2,sizeof(z2),0);
   x:=a[i];
   for j:=2 to trunc(sqrt(x)) do
    if x mod j=0 then
     while x mod j=0 do
      begin
       x:=x div j;
       inc(z2[j]);
      end;
   if x>1 then inc(z2[x]);
   x:=0;
   t[i]:=0;
   for k:=2 to max do
    begin
     if (z1[k]>0)and(z2[k]=0) then t[i]:=-1;
     if (t[i]>-1)and(z1[k]>0)and(z2[k]>0)and(x*z2[k]<z1[k]) then
      begin
       x:=z1[k] div z2[k];
       if x*z2[k]<z1[k] then inc(x);
      end;
    end;
   if t[i]>-1 then t[i]:=x;
  end;
 x:=-1;
 for i:=1 to n do if (t[i]>-1)and((x>t[i])or(x=-1)) then x:=t[i];
 writeln(x);
end.