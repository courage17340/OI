var
  a,h:array[0..20] of longint;
  n,i,j,b,ans:longint;
function sum:longint;
var i:longint;
begin
  sum:=0;
  for i:=1 to n do sum:=sum+a[i];
end;
begin
  readln(n,b);
  fillchar(a,sizeof(a),0);
  fillchar(h,sizeof(h),0);
  for i:=1 to n do read(h[i]);
  a[n]:=0;ans:=maxlongint;
  while sum<n do
    begin
      i:=n;
      while a[i]=1 do dec(i);
      a[i]:=1;
      for j:=i+1 to n do a[j]:=0;
      j:=0;
      for i:=1 to n do if a[i]=1 then j:=j+h[i];
      if (j>=b)and(j<ans) then ans:=j;
    end;
  writeln(ans-b);
end.