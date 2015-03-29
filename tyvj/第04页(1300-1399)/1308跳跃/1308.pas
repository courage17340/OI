var
  x,step,ans,k:longint;
begin
  ans:=maxlongint;
  read(x);
  step:=0;k:=x;
  while step<100000 do
    begin
      inc(step);
      k:=(k+k) mod 1000000007;
      k:=(k+k) mod 1000000007;
      k:=(k+k) mod 1000000007;
      k:=(k+7) mod 1000000007;
      if k=0 then begin if step<ans then ans:=step;break;end;
    end;
  k:=x;
  k:=(k+k) mod 1000000007;
  k:=(k+k) mod 1000000007;
  k:=(k+3) mod 1000000007;
  step:=1;
  while step<100000 do
    begin
      inc(step);
      k:=(k+k) mod 1000000007;
      k:=(k+k) mod 1000000007;
      k:=(k+k) mod 1000000007;
      k:=(k+7) mod 1000000007;
      if k=0 then begin if step<ans then ans:=step;break;end;
    end;
  k:=x;
  k:=(k+k) mod 1000000007;
  k:=(k+k) mod 1000000007;
  k:=(k+3) mod 1000000007;
  k:=(k+k) mod 1000000007;
  k:=(k+k) mod 1000000007;
  k:=(k+3) mod 1000000007;
  step:=2;
  while step<100000 do
    begin
      inc(step);
      k:=(k+k) mod 1000000007;
      k:=(k+k) mod 1000000007;
      k:=(k+k) mod 1000000007;
      k:=(k+7) mod 1000000007;
      if k=0 then begin if step<ans then ans:=step;break;end;
    end;
  if ans=maxlongint then writeln(-1) else writeln(ans);
end.
