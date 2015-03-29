var
  a:array[0..20000000] of boolean;
  i,j,t,n,p:longint;
  x:extended;
begin
  p:=0;
  fillchar(a,sizeof(a),false);
  readln(n);
  for i:=1 to n do
    begin
      readln(x,t);if x*t>20000000 then begin writeln(1000000000);halt;end;
      if p<trunc(x*t) then p:=trunc(x*t);
      for j:=1 to t do a[trunc(x*j)]:=not(a[trunc(x*j)]);
    end;
  for i:=1 to p do
    if a[i] then
      begin
        writeln(i);
        readln;
        halt;
      end;
end.