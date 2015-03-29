var
  v,t:array[1..10000] of longint;
  ans:extended;
  n,i,j:longint;
begin
  while true do
    begin
      readln(n);
      if n=0 then break;
      for i:=1 to n do readln(v[i],t[i]);
      i:=1;
      while t[i]<0 do inc(i);
      ans:=t[i]+4.5*3600/v[i];
      for j:=i+1 to n do
        if (t[j]>=0)and(ans>t[j]+4.5*3600/v[j]) then ans:=t[j]+4.5*3600/v[j];
      if ans-trunc(ans)>1e-7 then ans:=ans+1;
      writeln(trunc(ans));
    end;
end.