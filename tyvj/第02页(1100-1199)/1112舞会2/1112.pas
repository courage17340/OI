var
  a:array[1..201] of longint;
  n,k,ans,x,i:longint;
begin
  readln(n,k);
  ans:=0;
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      repeat
        read(x);
        if x>0 then inc(a[i]);
        until x=0;
      if a[i]>=k then inc(ans);
    end;
  writeln(ans);
end.